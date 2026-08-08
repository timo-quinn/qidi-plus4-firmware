from __future__ import annotations

import argparse
import importlib.util
import io
import json
import os
import pathlib
import subprocess
import tarfile

import pytest


MODULE_PATH = pathlib.Path(__file__).resolve().parents[1] / "qidi_plus4.py"
SPEC = importlib.util.spec_from_file_location("qidi_plus4", MODULE_PATH)
assert SPEC and SPEC.loader
qidi_plus4 = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(qidi_plus4)

BEACON_SERIAL = "/dev/serial/by-id/usb-Beacon_Beacon_RevH_TEST-if00"


def connection_args(command: str, **overrides: object) -> argparse.Namespace:
    values: dict[str, object] = {
        "command": command,
        "printer": "qidi2",
        "user": "mks",
        "port": 22,
        "identity": None,
    }
    values.update(overrides)
    return argparse.Namespace(**values)


def tiny_tar_gz() -> bytes:
    output = io.BytesIO()
    with tarfile.open(fileobj=output, mode="w:gz") as bundle:
        payload = b"backup proof\n"
        member = tarfile.TarInfo("proof.txt")
        member.size = len(payload)
        bundle.addfile(member, io.BytesIO(payload))
    return output.getvalue()


def canonical_plr_paths(account: str = "mks") -> dict[str, str]:
    home = f"/home/{account}"
    printer_data = f"{home}/printer_data"
    scripts_dir = f"{home}/scripts/plr"
    gcode_root = f"{printer_data}/gcodes"
    return {
        "home": home,
        "klipper_dir": f"{home}/klipper",
        "printer_data": printer_data,
        "scripts_dir": scripts_dir,
        "python": f"{home}/klippy-env/bin/python",
        "gcode_root": gcode_root,
        "checkpoint": f"{scripts_dir}/plr_checkpoint.json",
        "record": f"{scripts_dir}/plr_record",
        "output": f"{gcode_root}/.plr/plr.gcode",
    }


def render_args(
    profile_dir: pathlib.Path,
    output: pathlib.Path,
    *,
    force: bool = False,
) -> argparse.Namespace:
    return argparse.Namespace(
        profile=qidi_plus4.DEFAULT_CONFIG_PROFILE,
        profile_dir=profile_dir,
        beacon_serial=BEACON_SERIAL,
        output=output,
        force=force,
    )


def test_parser_exposes_host_tuning_commands() -> None:
    parser = qidi_plus4.create_parser()

    audit = parser.parse_args(["audit-host-tuning", "--printer", "qidi2"])
    tune = parser.parse_args(["tune-host", "--printer", "qidi2", "--confirm", "TUNE-HOST"])

    assert audit.func is qidi_plus4.host_tuning
    assert tune.func is qidi_plus4.host_tuning
    assert tune.confirm == "TUNE-HOST"


def test_backup_remote_defaults_stay_on_root_filesystem_and_exclude_all_gcodes() -> None:
    helper = qidi_plus4.BACKUP_HELPER.read_text(encoding="utf-8")

    assert "--one-file-system" in helper
    assert "--ignore-failed-read" not in helper
    assert "--exclude=home/mks/printer_data/gcodes" in helper
    assert "--exclude=home/mks/gcode_files" in helper


def test_backup_publishes_only_after_partial_archive_is_verified(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    commands: list[list[str]] = []
    streamed_paths: list[pathlib.Path] = []
    payload = tiny_tar_gz()
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_run(command: list[str], input_data: bytes | None = None) -> None:
        commands.append(command)
        if command[0] == "scp" and command[1].startswith("mks@qidi1:"):
            pathlib.Path(command[-1]).write_text("manifest proof\n", encoding="utf-8")

    def fake_subprocess_run(
        command: list[str], **kwargs: object
    ) -> subprocess.CompletedProcess[bytes]:
        commands.append(command)
        stdout = kwargs.get("stdout")
        if hasattr(stdout, "write"):
            streamed_paths.append(pathlib.Path(stdout.name))
            stdout.write(payload)
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4, "run", fake_run)
    monkeypatch.setattr(qidi_plus4.subprocess, "run", fake_subprocess_run)
    args = connection_args(
        "backup",
        name="qidi1",
        output=tmp_path,
        include_gcodes=False,
        include_logs=False,
        include_environments=False,
    )

    qidi_plus4.backup_printer(args)

    destination = tmp_path / "qidi1"
    archives = list(destination.glob("*.tar.gz"))
    assert len(archives) == 1
    archive = archives[0]
    assert streamed_paths == [archive.with_name(archive.name + ".partial")]
    assert not list(destination.glob("*.partial"))
    manifest = destination / archive.name.replace(".tar.gz", "-manifest.txt")
    checksum = archive.with_suffix(archive.suffix + ".sha256")
    assert manifest.read_text(encoding="utf-8") == "manifest proof\n"
    assert checksum.read_text(encoding="ascii") == (
        f"{qidi_plus4.sha256(archive)}  {archive.name}\n"
    )
    with tarfile.open(archive, "r:gz") as bundle:
        assert bundle.getnames() == ["proof.txt"]
    backup_commands = [command for command in commands if command[:2] == ["ssh", "qidi1"]]
    assert any(" 0 0 0" in command[-1] for command in backup_commands)


def test_failed_backup_removes_partial_and_never_publishes_archive(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    payload = tiny_tar_gz()
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])
    monkeypatch.setattr(qidi_plus4, "run", lambda command, input_data=None: None)

    def fake_subprocess_run(
        command: list[str], **kwargs: object
    ) -> subprocess.CompletedProcess[bytes]:
        stdout = kwargs.get("stdout")
        if hasattr(stdout, "write"):
            stdout.write(payload)
            return subprocess.CompletedProcess(command, 9, b"", b"failed")
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4.subprocess, "run", fake_subprocess_run)
    args = connection_args(
        "backup",
        name="qidi1",
        output=tmp_path,
        include_gcodes=False,
        include_logs=False,
        include_environments=False,
    )

    with pytest.raises(SystemExit, match="Remote backup failed"):
        qidi_plus4.backup_printer(args)

    destination = tmp_path / "qidi1"
    assert list(destination.iterdir()) == []


def test_parser_validates_password_environment_names() -> None:
    parser = qidi_plus4.create_parser()
    args = parser.parse_args(
        [
            "setup-ssh",
            "--printer",
            "qidi1",
            "--password-env",
            "QIDI1_BOOTSTRAP_PASSWORD",
        ]
    )
    assert args.password_env == "QIDI1_BOOTSTRAP_PASSWORD"

    with pytest.raises(SystemExit):
        parser.parse_args(["setup-ssh", "--printer", "qidi1", "--password-env", "bad-name"])
    with pytest.raises(SystemExit):
        parser.parse_args(["setup-ssh", "--printer", "qidi1", "--password-env", "SSH_ASKPASS"])


@pytest.mark.parametrize(
    ("arguments", "message"),
    [
        (["--printer=-oProxyCommand=bad"], "printer host"),
        (["--printer", "qidi1/../../tmp"], "printer host"),
        (["--printer", "qidi1", "--user", "mks@other"], "account name"),
        (["--printer", "qidi1", "--printer-user", "bad user"], "account name"),
        (["--printer", "qidi1", "--port", "0"], "between 1 and 65535"),
        (["--printer", "qidi1", "--port", "65536"], "between 1 and 65535"),
    ],
)
def test_parser_rejects_unsafe_ssh_connection_values(
    arguments: list[str], message: str, capsys: pytest.CaptureFixture[str]
) -> None:
    parser = qidi_plus4.create_parser()
    with pytest.raises(SystemExit):
        parser.parse_args(["audit", *arguments])
    assert message in capsys.readouterr().err


def test_ssh_builder_revalidates_library_callers_before_command_lookup(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setattr(
        qidi_plus4,
        "require_command",
        lambda _name: pytest.fail("unsafe connection reached command lookup"),
    )
    args = connection_args("audit", printer="-Fbad", user="mks", port=22)
    with pytest.raises(SystemExit, match="Invalid SSH connection"):
        qidi_plus4.ssh_base(args)


def test_password_auth_forces_askpass_and_disables_keys_and_mux(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: pathlib.Path,
) -> None:
    askpass = tmp_path / "plab-askpass"
    askpass.write_text("#!/bin/sh\n", encoding="utf-8")
    askpass.chmod(0o700)
    monkeypatch.setenv("QIDI1_BOOTSTRAP_PASSWORD", "not-in-command")
    monkeypatch.setenv("SSH_ASKPASS", str(askpass.resolve()))
    monkeypatch.setenv("SSH_ASKPASS_REQUIRE", "force")
    monkeypatch.setattr(qidi_plus4, "require_command", lambda name: name)
    monkeypatch.setattr(
        qidi_plus4,
        "mux_options",
        lambda: ["-o", "ControlMaster=auto"],
    )
    args = connection_args(
        "setup-ssh",
        password_env="QIDI1_BOOTSTRAP_PASSWORD",
        identity="must-be-ignored",
    )

    ssh, target = qidi_plus4.ssh_base(args)
    scp = qidi_plus4.scp_base(args)

    assert target == "mks@qidi2"
    for command in (ssh, scp):
        joined = " ".join(command)
        assert "BatchMode=no" in joined
        assert "PubkeyAuthentication=no" in joined
        assert "PreferredAuthentications=password,keyboard-interactive" in joined
        assert "NumberOfPasswordPrompts=1" in joined
        assert "ControlMaster" not in joined
        assert "must-be-ignored" not in joined
        assert "not-in-command" not in joined


def test_password_auth_fails_before_connection_when_secret_or_askpass_is_missing(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: pathlib.Path,
) -> None:
    args = connection_args(
        "setup-ssh",
        password_env="QIDI1_BOOTSTRAP_PASSWORD",
    )
    monkeypatch.delenv("QIDI1_BOOTSTRAP_PASSWORD", raising=False)
    with pytest.raises(SystemExit, match="empty or unset"):
        qidi_plus4.password_auth_options(args)

    monkeypatch.setenv("QIDI1_BOOTSTRAP_PASSWORD", "secret")
    monkeypatch.delenv("SSH_ASKPASS", raising=False)
    with pytest.raises(SystemExit, match="requires SSH_ASKPASS"):
        qidi_plus4.password_auth_options(args)

    askpass = tmp_path / "askpass"
    askpass.write_text("askpass\n", encoding="utf-8")
    askpass.chmod(0o700)
    monkeypatch.setenv("SSH_ASKPASS", str(askpass.resolve()))
    monkeypatch.delenv("SSH_ASKPASS_REQUIRE", raising=False)
    with pytest.raises(SystemExit, match="SSH_ASKPASS_REQUIRE=force"):
        qidi_plus4.password_auth_options(args)


def test_default_key_authentication_options_remain_unchanged(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: pathlib.Path,
) -> None:
    identity = tmp_path / "id_ed25519"
    identity.write_text("test key", encoding="utf-8")
    monkeypatch.setattr(qidi_plus4, "require_command", lambda name: name)
    monkeypatch.setattr(qidi_plus4, "mux_options", lambda: [])
    args = connection_args("audit", identity=str(identity), password_env=None)

    ssh, _ = qidi_plus4.ssh_base(args)
    joined = " ".join(ssh)

    assert f"-i {identity}" in joined
    assert "IdentitiesOnly=yes" in joined
    assert "PubkeyAuthentication=no" not in joined
    assert "PreferredAuthentications" not in joined


def test_parser_exposes_guarded_plr_deploy_start_and_rollback_commands() -> None:
    parser = qidi_plus4.create_parser()
    deploy = parser.parse_args(
        [
            "deploy-plr-hardening",
            "--printer",
            "qidi1",
            "--confirm",
            "DEPLOY-PLR-HARDENING",
        ]
    )
    start = parser.parse_args(
        [
            "start-klipper",
            "--printer",
            "qidi1",
            "--confirm",
            "START-KLIPPER",
        ]
    )
    rollback = parser.parse_args(
        [
            "rollback-plr-hardening",
            "--printer",
            "qidi1",
            "--confirm",
            "ROLLBACK-PLR-HARDENING",
            "--backup-manifest",
            "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-x/backup-manifest.json",
        ]
    )

    assert deploy.func is qidi_plus4.deploy_plr_hardening
    assert start.func is qidi_plus4.start_klipper
    assert rollback.func is qidi_plus4.rollback_plr_hardening


def test_remote_json_preserves_structured_installer_error(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    command = ["ssh", "qidi1", "install.py --json"]
    document = {
        "ok": False,
        "error": "PLR scripts directory does not exist: /home/mks/scripts/plr",
        "transaction_state": "not_started",
    }
    monkeypatch.setattr(
        qidi_plus4,
        "capture",
        lambda observed: subprocess.CompletedProcess(
            observed,
            1,
            json.dumps(document).encode("utf-8"),
            b"",
        ),
    )

    with pytest.raises(
        qidi_plus4.RemoteJsonError,
        match=r"exited 1: PLR scripts directory does not exist",
    ) as raised:
        qidi_plus4._remote_json(command[:-1], command[-1])

    assert raised.value.document == document
    assert raised.value.returncode == 1


def test_refresh_klippee_agent_restarts_only_fixed_user_unit(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    parsed = qidi_plus4.create_parser().parse_args(
        [
            "refresh-klippee-agent",
            "--printer",
            "qidi1",
            "--confirm",
            "REFRESH-KLIPPEE-AGENT",
        ]
    )
    assert parsed.func is qidi_plus4.refresh_klippee_agent

    calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append(command)
        if "is-active" in command[-1]:
            return subprocess.CompletedProcess(command, 0, b"active\n", b"")
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    args = connection_args("refresh-klippee-agent", confirm="REFRESH-KLIPPEE-AGENT")

    qidi_plus4.refresh_klippee_agent(args)

    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is True
    assert result["service"] == "klippee-moonraker.service"
    assert result["klipper_actions_performed"] is False
    assert result["config_deployment_performed"] is False
    assert calls == [
        ["ssh", "qidi1", "systemctl --user restart klippee-moonraker.service"],
        ["ssh", "qidi1", "systemctl --user is-active klippee-moonraker.service"],
    ]


def test_refresh_klippee_agent_targets_printer_users_user_bus(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "plab@qidi1"], "plab@qidi1"))

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append(command)
        if "is-active" in command[-1]:
            return subprocess.CompletedProcess(command, 0, b"active\n", b"")
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    args = connection_args(
        "refresh-klippee-agent",
        user="plab",
        printer_user="mks",
        confirm="REFRESH-KLIPPEE-AGENT",
    )

    qidi_plus4.refresh_klippee_agent(args)

    result = json.loads(capsys.readouterr().out)
    assert result["account"] == "mks"
    for command in calls:
        remote = command[-1]
        assert "sudo -n -u mks" in remote
        assert "XDG_RUNTIME_DIR=/run/user/$uid" in remote
        assert "systemctl --user" in remote
        assert "sudo -n systemctl" not in remote


def test_refresh_klippee_agent_requires_exact_confirmation_before_ssh(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: pytest.fail("confirmation must precede SSH construction"),
    )
    args = connection_args("refresh-klippee-agent", confirm="wrong")
    with pytest.raises(SystemExit, match="REFRESH-KLIPPEE-AGENT"):
        qidi_plus4.refresh_klippee_agent(args)


def test_parser_exposes_fixed_box_clock_guard_installer() -> None:
    parsed = qidi_plus4.create_parser().parse_args(
        [
            "install-box-output-clock-guard",
            "--printer",
            "qidi1",
            "--confirm",
            "INSTALL-BOX-OUTPUT-CLOCK-GUARD",
        ]
    )

    assert parsed.func is qidi_plus4.install_box_output_clock_guard
    assert not hasattr(parsed, "source")
    assert not hasattr(parsed, "target")
    assert not hasattr(parsed, "mode")
    assert not hasattr(parsed, "remote_python")


def test_parser_exposes_fixed_box_motion_template_guard() -> None:
    parsed = qidi_plus4.create_parser().parse_args(
        [
            "harden-box-motion-template",
            "--printer",
            "qidi1",
            "--box-count",
            "1",
            "--confirm",
            "HARDEN-BOX-MOTION-TEMPLATE",
        ]
    )

    assert parsed.func is qidi_plus4.harden_box_motion_template
    assert parsed.box_count == 1
    assert not hasattr(parsed, "target")
    assert not hasattr(parsed, "remote_python")


def test_parser_exposes_fixed_box_motion_vendor_restore() -> None:
    parsed = qidi_plus4.create_parser().parse_args(
        [
            "restore-box-motion-template",
            "--printer",
            "qidi1",
            "--box-count",
            "1",
            "--confirm",
            "RESTORE-BOX-MOTION-VENDOR",
        ]
    )

    assert parsed.func is qidi_plus4.restore_box_motion_template
    assert parsed.box_count == 1
    assert not hasattr(parsed, "target")
    assert not hasattr(parsed, "remote_python")


def test_box_motion_template_guard_streams_fixed_helper_without_restart(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
) -> None:
    transaction_id = "20260806T010203Z-0123456789abcdef"
    before = "1" * 64
    after = "2" * 64
    remote_result = {
        "schema": qidi_plus4.BOX_MOTION_GUARD_SCHEMA,
        "ok": True,
        "changed": True,
        "verified": True,
        "box_count": 1,
        "transaction_id": transaction_id,
        "target": {
            "path": "/home/mks/cfg_with_1",
            "before_sha256": before,
            "after_sha256": after,
            "mode": "0644",
            "uid": 0,
            "gid": 0,
        },
        "backup": {
            "path": (f"/home/mks/.qidi-plus4-backups/box-motion-guard-{transaction_id}/cfg_with_1"),
            "sha256": before,
        },
        "use_irq": False,
        "debounce_us_present": False,
        "active_config_changed": False,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "activation_required": True,
    }
    calls: list[tuple[list[str], bytes | None]] = []
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: (["ssh", "qidi1"], "plab@qidi1"),
    )
    monkeypatch.setattr(
        qidi_plus4,
        "_box_clock_guard_transaction_id",
        lambda: transaction_id,
    )

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append((command, input_data))
        return subprocess.CompletedProcess(command, 0, json.dumps(remote_result).encode(), b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    qidi_plus4.harden_box_motion_template(
        connection_args(
            "harden-box-motion-template",
            confirm="HARDEN-BOX-MOTION-TEMPLATE",
            box_count=1,
            user="plab",
            printer_user="mks",
        )
    )

    result = json.loads(capsys.readouterr().out)
    assert result["target"]["after_sha256"] == after
    assert len(calls) == 1
    command, helper = calls[0]
    assert helper == qidi_plus4.BOX_MOTION_GUARD_REMOTE_INSTALLER.read_bytes()
    assert "sudo -n /usr/bin/python3 -I -" in command[-1]
    assert "--box-count 1" in command[-1]
    assert transaction_id in command[-1]
    assert "systemctl" not in command[-1]
    assert "restart" not in command[-1]


def test_box_motion_vendor_restore_streams_fixed_helper_without_restart(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
) -> None:
    transaction_id = "20260806T010203Z-0123456789abcdef"
    before = "1" * 64
    remote_result = {
        "schema": qidi_plus4.BOX_MOTION_GUARD_SCHEMA,
        "ok": True,
        "changed": True,
        "verified": True,
        "box_count": 1,
        "transaction_id": transaction_id,
        "target": {
            "path": "/home/mks/cfg_with_1",
            "before_sha256": before,
            "after_sha256": "2" * 64,
            "mode": "0644",
            "uid": 0,
            "gid": 0,
        },
        "backup": {
            "path": f"/home/mks/.qidi-plus4-backups/box-motion-vendor-{transaction_id}/cfg_with_1",
            "sha256": before,
        },
        "use_irq": True,
        "debounce_us_present": True,
        "active_config_changed": False,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "activation_required": True,
    }
    calls: list[tuple[list[str], bytes | None]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "plab@qidi1"))
    monkeypatch.setattr(qidi_plus4, "_box_clock_guard_transaction_id", lambda: transaction_id)

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append((command, input_data))
        return subprocess.CompletedProcess(command, 0, json.dumps(remote_result).encode(), b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    qidi_plus4.restore_box_motion_template(
        connection_args(
            "restore-box-motion-template",
            confirm="RESTORE-BOX-MOTION-VENDOR",
            box_count=1,
            user="plab",
            printer_user="mks",
        )
    )

    result = json.loads(capsys.readouterr().out)
    assert result["use_irq"] is True
    assert result["debounce_us_present"] is True
    command, helper = calls[0]
    assert helper == qidi_plus4.BOX_MOTION_GUARD_REMOTE_INSTALLER.read_bytes()
    assert "--restore-vendor" in command[-1]
    assert "systemctl" not in command[-1]
    assert "restart" not in command[-1]


def test_set_klippee_variable_uses_fixed_cli_and_verifies_without_restart(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
) -> None:
    calls: list[list[str]] = []
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: (["ssh", "qidi1"], "plab@qidi1"),
    )

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        assert input_data is None
        calls.append(command)
        return subprocess.CompletedProcess(command, 0, b"verified\n", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    value = "/dev/serial/by-id/usb-QIDI_TEST"
    qidi_plus4.set_klippee_variable(
        connection_args(
            "set-klippee-variable",
            confirm="SET-KLIPPEE-VARIABLE",
            name="qidi_box_serial",
            value=value,
            user="plab",
            printer_user="mks",
        )
    )

    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is True
    assert result["verified"] is True
    assert result["name"] == "qidi_box_serial"
    assert result["value_sha256"] == qidi_plus4.hashlib.sha256(value.encode()).hexdigest()
    assert value not in json.dumps(result)
    assert len(calls) == 2
    assert qidi_plus4.KLIPPEE_VARIABLE_CLI in calls[0][-1]
    assert "variables set qidi_box_serial" in calls[0][-1]
    assert "variables doctor" in calls[1][-1]
    assert "systemctl" not in "\n".join(call[-1] for call in calls)
    assert "restart" not in "\n".join(call[-1] for call in calls)


def test_set_klippee_variable_rejects_unsafe_name_before_ssh(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: pytest.fail("invalid variable must not reach SSH"),
    )
    with pytest.raises(SystemExit, match="name is invalid"):
        qidi_plus4.set_klippee_variable(
            connection_args(
                "set-klippee-variable",
                confirm="SET-KLIPPEE-VARIABLE",
                name="bad;name",
                value="value",
                printer_user="mks",
            )
        )


def test_box_clock_guard_installer_requires_confirmation_and_fixed_owner_before_ssh(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: pytest.fail("local safety checks must precede SSH construction"),
    )

    with pytest.raises(SystemExit, match="INSTALL-BOX-OUTPUT-CLOCK-GUARD"):
        qidi_plus4.install_box_output_clock_guard(
            connection_args("install-box-output-clock-guard", confirm="yes")
        )

    with pytest.raises(SystemExit, match="fixed stock Klipper account mks"):
        qidi_plus4.install_box_output_clock_guard(
            connection_args(
                "install-box-output-clock-guard",
                confirm="INSTALL-BOX-OUTPUT-CLOCK-GUARD",
                printer_user="root",
            )
        )


def test_box_clock_guard_installer_uploads_only_reviewed_asset_and_never_restarts(
    monkeypatch: pytest.MonkeyPatch,
    capsys: pytest.CaptureFixture[str],
) -> None:
    stage = "/tmp/qidi-box-clock-guard.A1b2C3d4"
    transaction_id = "20260806T010203Z-0123456789abcdef"
    digest = qidi_plus4.sha256(qidi_plus4.BOX_CLOCK_GUARD_SOURCE)
    backup_path = (
        "/home/mks/klipper/klippy/extras/.qidi-plus4-backups/"
        f"box-output-clock-guard-{transaction_id}/box_output_clock_guard.py"
    )
    remote_result = {
        "schema": qidi_plus4.BOX_CLOCK_GUARD_SCHEMA,
        "ok": True,
        "changed": True,
        "applied": True,
        "verified": True,
        "account": "mks",
        "transaction_id": transaction_id,
        "source_sha256": digest,
        "target": {
            "path": qidi_plus4.BOX_CLOCK_GUARD_TARGET,
            "sha256": digest,
            "owner": "mks",
            "group": "mks",
            "mode": "0644",
        },
        "backup": {
            "path": backup_path,
            "sha256": "0" * 64,
            "owner": "mks",
            "group": "mks",
            "mode": "0644",
        },
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "config_changed": False,
        "activation_required": True,
        "required_config_section": "[box_output_clock_guard]",
    }
    calls: list[tuple[list[str], bytes | None]] = []
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: (["ssh", "qidi1"], "mks@qidi1"),
    )
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])
    monkeypatch.setattr(
        qidi_plus4,
        "_box_clock_guard_transaction_id",
        lambda: transaction_id,
    )

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append((command, input_data))
        if command[-1] == "mktemp -d /tmp/qidi-box-clock-guard.XXXXXXXX":
            return subprocess.CompletedProcess(command, 0, (stage + "\n").encode(), b"")
        if input_data is not None:
            return subprocess.CompletedProcess(command, 0, json.dumps(remote_result).encode(), b"")
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    args = connection_args(
        "install-box-output-clock-guard",
        confirm="INSTALL-BOX-OUTPUT-CLOCK-GUARD",
        printer_user=None,
    )

    qidi_plus4.install_box_output_clock_guard(args)

    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is True
    assert result["target"]["sha256"] == digest
    assert result["backup"]["path"] == backup_path
    assert result["klipper_service_action"] == "none"
    assert result["klipper_restarted"] is False
    assert result["config_changed"] is False
    assert result["staging_cleanup_verified"] is True

    scp_calls = [command for command, _input in calls if command[0] == "scp"]
    assert scp_calls == [
        [
            "scp",
            str(qidi_plus4.BOX_CLOCK_GUARD_SOURCE.resolve()),
            f"mks@qidi1:{stage}/box_output_clock_guard.py",
        ]
    ]
    streamed = [(command, data) for command, data in calls if data is not None]
    assert len(streamed) == 1
    remote_command, helper = streamed[0]
    assert helper == qidi_plus4.BOX_CLOCK_GUARD_REMOTE_INSTALLER.read_bytes()
    assert qidi_plus4.BOX_CLOCK_GUARD_REMOTE_PYTHON in remote_command[-1]
    assert " -I - " in remote_command[-1]
    assert digest in remote_command[-1]
    assert transaction_id in remote_command[-1]
    assert qidi_plus4.BOX_CLOCK_GUARD_TARGET not in remote_command[-1]
    all_commands = "\n".join(" ".join(command) for command, _input in calls)
    assert "systemctl" not in all_commands
    assert "restart" not in all_commands


def test_box_clock_guard_proof_rejects_wrong_remote_digest() -> None:
    expected = "1" * 64
    document = {
        "schema": qidi_plus4.BOX_CLOCK_GUARD_SCHEMA,
        "ok": True,
        "changed": False,
        "applied": False,
        "verified": True,
        "account": "mks",
        "transaction_id": "20260806T010203Z-0123456789abcdef",
        "source_sha256": expected,
        "target": {
            "path": qidi_plus4.BOX_CLOCK_GUARD_TARGET,
            "sha256": "2" * 64,
            "owner": "mks",
            "group": "mks",
            "mode": "0644",
        },
        "backup": None,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "config_changed": False,
        "activation_required": True,
        "required_config_section": "[box_output_clock_guard]",
    }
    completed = subprocess.CompletedProcess(["ssh"], 0, json.dumps(document).encode(), b"")

    with pytest.raises(
        qidi_plus4.BoxClockGuardInstallError,
        match="digest or metadata was not verified",
    ):
        qidi_plus4._validated_box_clock_guard_result(
            completed,
            expected_digest=expected,
            transaction_id="20260806T010203Z-0123456789abcdef",
        )


def test_remote_box_clock_guard_helper_has_fixed_install_boundary() -> None:
    helper = qidi_plus4.BOX_CLOCK_GUARD_REMOTE_INSTALLER.read_text(encoding="utf-8")

    assert 'OWNER = "mks"' in helper
    assert '"/home/mks/klipper/klippy/extras/box_output_clock_guard.py"' in helper
    assert "MODE = 0o644" in helper
    assert 'parser.add_argument("--target"' not in helper
    assert 'parser.add_argument("--owner"' not in helper
    assert 'parser.add_argument("--mode"' not in helper
    assert "systemctl" not in helper
    assert "subprocess" not in helper


@pytest.mark.skipif(os.name == "nt", reason="remote helper targets a POSIX QIDI host")
def test_remote_box_clock_guard_helper_preserves_timestamped_backup(
    monkeypatch: pytest.MonkeyPatch,
    tmp_path: pathlib.Path,
) -> None:
    helper_path = qidi_plus4.BOX_CLOCK_GUARD_REMOTE_INSTALLER
    spec = importlib.util.spec_from_file_location("box_clock_guard_installer", helper_path)
    assert spec and spec.loader
    helper = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(helper)
    current_owner = helper.pwd.getpwuid(os.getuid()).pw_name
    source = tmp_path / "source.py"
    target = tmp_path / "extras" / "box_output_clock_guard.py"
    target.parent.mkdir()
    source.write_bytes(b"reviewed clock guard\n")
    target.write_bytes(b"old clock guard\n")
    target.chmod(0o600)
    monkeypatch.setattr(helper.os, "chown", lambda _path, _uid, _gid: None)
    transaction_id = "20260806T010203Z-0123456789abcdef"

    result = helper.install(
        source,
        helper.sha256(source),
        transaction_id,
        target=target,
        owner_name=current_owner,
    )

    assert result["ok"] is True
    assert result["changed"] is True
    assert result["target"]["sha256"] == helper.sha256(source)
    assert result["target"]["mode"] == "0644"
    backup = pathlib.Path(result["backup"]["path"])
    assert transaction_id in str(backup)
    assert backup.read_bytes() == b"old clock guard\n"
    assert result["klipper_restarted"] is False


def test_start_klipper_only_starts_exact_unit_and_verifies_active(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append(command)
        if "is-active" in command[-1]:
            return subprocess.CompletedProcess(command, 0, b"active\n", b"")
        return subprocess.CompletedProcess(command, 0, b"", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(qidi_plus4.time, "sleep", lambda _seconds: None)
    args = connection_args(
        "start-klipper",
        confirm="START-KLIPPER",
        service="klipper.service",
        rollback_manifest=None,
        scripts_dir="/home/mks/scripts/plr",
    )

    qidi_plus4.start_klipper(args)

    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is True
    assert result["config_or_file_reads_performed"] is False
    assert calls[0] == ["ssh", "qidi1", "sudo -n systemctl start klipper.service"]
    assert (
        calls[1:]
        == [["ssh", "qidi1", "systemctl is-active klipper.service"]]
        * qidi_plus4.KLIPPER_START_STABILITY_CHECKS
    )
    assert len(result["stability_samples"]) == qidi_plus4.KLIPPER_START_STABILITY_CHECKS


def test_plr_operations_reject_every_service_except_exact_klipper_unit(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    monkeypatch.setattr(
        qidi_plus4,
        "ssh_base",
        lambda _args: pytest.fail("service validation must precede SSH"),
    )
    args = connection_args(
        "start-klipper",
        confirm="START-KLIPPER",
        service="moonraker.service",
        rollback_manifest=None,
        scripts_dir="/home/mks/scripts/plr",
    )
    with pytest.raises(SystemExit, match="exactly klipper.service"):
        qidi_plus4.start_klipper(args)


def test_start_klipper_rejects_service_that_dies_during_stability_window(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    state_reads = 0
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        nonlocal state_reads
        if "is-active" not in command[-1]:
            return subprocess.CompletedProcess(command, 0, b"", b"")
        state_reads += 1
        if state_reads < 3:
            return subprocess.CompletedProcess(command, 0, b"active\n", b"")
        return subprocess.CompletedProcess(command, 3, b"failed\n", b"")

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(qidi_plus4.time, "sleep", lambda _seconds: None)
    args = connection_args(
        "start-klipper",
        confirm="START-KLIPPER",
        service="klipper.service",
        rollback_manifest=(
            "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-test/backup-manifest.json"
        ),
        scripts_dir="/home/mks/scripts/plr",
    )

    with pytest.raises(SystemExit) as failure:
        qidi_plus4.start_klipper(args)

    assert failure.value.code == 1
    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is False
    assert result["observed_state"] == "failed"
    assert len(result["stability_samples"]) == 3
    assert "rollback-plr-hardening" in result["next_command"]


def test_deploy_plr_hardening_stops_applies_verifies_and_never_restarts(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    calls: list[list[str]] = []
    installer_reads = 0
    paths = canonical_plr_paths()
    backup_manifest = (
        "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-test/backup-manifest.json"
    )
    monkeypatch.setattr(qidi_plus4, "_plr_transaction_id", lambda: "20260806T000000Z-test")
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        nonlocal installer_reads
        calls.append(command)
        joined = " ".join(command)
        if "mktemp -d" in joined:
            return subprocess.CompletedProcess(command, 0, b"/tmp/qidi-plr-hardening.ABC123\n", b"")
        if command[0] == "scp" or "systemctl stop" in joined:
            return subprocess.CompletedProcess(command, 0, b"", b"")
        if "systemctl is-active" in joined:
            return subprocess.CompletedProcess(command, 3, b"inactive\n", b"")
        if "install.py" in joined:
            installer_reads += 1
            if "--apply" in joined:
                document = {
                    "ok": True,
                    "changed": True,
                    "applied": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": "applied",
                }
            elif installer_reads == 1:
                document = {
                    "ok": True,
                    "changed": True,
                    "dry_run": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": "not_started",
                }
            else:
                document = {
                    "ok": True,
                    "changed": False,
                    "dry_run": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": None,
                    "safety_manifest": None,
                    "transaction_state": "not_started",
                }
            return subprocess.CompletedProcess(
                command, 0, json.dumps(document).encode("utf-8"), b""
            )
        raise AssertionError(command)

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(
        qidi_plus4.subprocess,
        "run",
        lambda command, **_kwargs: subprocess.CompletedProcess(command, 0),
    )
    args = connection_args(
        "deploy-plr-hardening",
        confirm="DEPLOY-PLR-HARDENING",
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
        service="klipper.service",
    )

    qidi_plus4.deploy_plr_hardening(args)

    result = json.loads(capsys.readouterr().out)
    assert result["applied"] is True
    assert result["transaction_state"] == "applied"
    assert result["verified"] is True
    assert result["klipper_left_stopped"] is True
    assert result["backup_manifest"] == result["installation"]["backup_manifest"]
    all_commands = "\n".join(" ".join(command) for command in calls)
    assert "systemctl stop klipper.service" in all_commands
    assert "--apply --klipper-stopped" in all_commands
    assert "systemctl start" not in all_commands
    assert "systemctl restart" not in all_commands


def test_deploy_plr_failure_preserves_backup_manifest_after_apply(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    calls: list[list[str]] = []
    installer_reads = 0
    backup_manifest = (
        "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-proof/backup-manifest.json"
    )
    paths = canonical_plr_paths()
    monkeypatch.setattr(qidi_plus4, "_plr_transaction_id", lambda: "20260806T000000Z-proof")
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        nonlocal installer_reads
        calls.append(command)
        joined = " ".join(command)
        if "mktemp -d" in joined:
            return subprocess.CompletedProcess(command, 0, b"/tmp/qidi-plr-hardening.PROOF1\n", b"")
        if command[0] == "scp" or "systemctl stop" in joined:
            return subprocess.CompletedProcess(command, 0, b"", b"")
        if "systemctl is-active" in joined:
            return subprocess.CompletedProcess(command, 3, b"inactive\n", b"")
        if "install.py" in joined:
            installer_reads += 1
            if installer_reads == 1:
                document = {
                    "ok": True,
                    "changed": True,
                    "dry_run": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": "not_started",
                }
                return subprocess.CompletedProcess(
                    command, 0, json.dumps(document).encode("utf-8"), b""
                )
            if installer_reads == 2:
                document = {
                    "ok": True,
                    "changed": True,
                    "applied": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": "applied",
                }
                return subprocess.CompletedProcess(
                    command, 0, json.dumps(document).encode("utf-8"), b""
                )
            document = {
                "ok": False,
                "changed": False,
                "error": "post-install verification failed",
                "account": "mks",
                "paths": paths,
                "applied": False,
                "backup_manifest": None,
                "safety_manifest": None,
                "transaction_state": "not_started",
            }
            return subprocess.CompletedProcess(
                command,
                7,
                json.dumps(document).encode("utf-8"),
                b"verification command failed\n",
            )
        raise AssertionError(command)

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(
        qidi_plus4.subprocess,
        "run",
        lambda command, **_kwargs: subprocess.CompletedProcess(command, 0),
    )
    args = connection_args(
        "deploy-plr-hardening",
        confirm="DEPLOY-PLR-HARDENING",
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
        service="klipper.service",
    )

    with pytest.raises(SystemExit) as failure:
        qidi_plus4.deploy_plr_hardening(args)

    assert failure.value.code == 1
    captured = capsys.readouterr()
    result = json.loads(captured.out)
    assert result["ok"] is False
    assert result["phase"] == "verify"
    assert result["applied"] is None
    assert result["transaction_state"] == "indeterminate"
    assert result["verified"] is False
    assert result["klipper_left_stopped"] is True
    assert result["backup_manifest"] == backup_manifest
    assert result["installation"]["backup_manifest"] == backup_manifest
    assert result["verification"]["error"] == "post-install verification failed"
    assert backup_manifest in result["next_command"]
    assert "deliberately been left stopped" in captured.err
    assert not any("systemctl start" in " ".join(call) for call in calls)


def test_deploy_transport_loss_keeps_predeclared_backup_handle(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    paths = canonical_plr_paths()
    backup_manifest = (
        "/home/mks/scripts/plr/backups/"
        "plr-hardening-20260806T000000Z-transport/backup-manifest.json"
    )
    installer_reads = 0
    monkeypatch.setattr(
        qidi_plus4,
        "_plr_transaction_id",
        lambda: "20260806T000000Z-transport",
    )
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        nonlocal installer_reads
        joined = " ".join(command)
        if "mktemp -d" in joined:
            return subprocess.CompletedProcess(command, 0, b"/tmp/qidi-plr-hardening.LOST1\n", b"")
        if command[0] == "scp" or "systemctl stop" in joined:
            return subprocess.CompletedProcess(command, 0, b"", b"")
        if "systemctl is-active" in joined:
            return subprocess.CompletedProcess(command, 3, b"inactive\n", b"")
        if "install.py" in joined:
            installer_reads += 1
            if installer_reads == 1:
                document = {
                    "ok": True,
                    "changed": True,
                    "account": "mks",
                    "paths": paths,
                    "backup_manifest": backup_manifest,
                    "safety_manifest": None,
                    "transaction_state": "not_started",
                }
                return subprocess.CompletedProcess(
                    command, 0, json.dumps(document).encode("utf-8"), b""
                )
            return subprocess.CompletedProcess(command, 255, b"", b"connection reset after apply\n")
        raise AssertionError(command)

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(
        qidi_plus4.subprocess,
        "run",
        lambda command, **_kwargs: subprocess.CompletedProcess(command, 0),
    )
    args = connection_args(
        "deploy-plr-hardening",
        confirm="DEPLOY-PLR-HARDENING",
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
        service="klipper.service",
    )

    with pytest.raises(SystemExit) as failure:
        qidi_plus4.deploy_plr_hardening(args)

    assert failure.value.code == 1
    result = json.loads(capsys.readouterr().out)
    assert result["phase"] == "apply"
    assert result["transaction_state"] == "indeterminate"
    assert result["applied"] is None
    assert result["backup_manifest"] == backup_manifest
    assert result["safety_manifest"] is None
    assert result["installation"] is None
    assert backup_manifest in result["next_command"]


def test_rollback_unchanged_echoes_validated_backup_manifest(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    backup_manifest = (
        "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-proof/backup-manifest.json"
    )
    paths = canonical_plr_paths()
    calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        calls.append(command)
        joined = " ".join(command)
        if "mktemp -d" in joined:
            return subprocess.CompletedProcess(command, 0, b"/tmp/qidi-plr-hardening.ROLL1\n", b"")
        if command[0] == "scp":
            return subprocess.CompletedProcess(command, 0, b"", b"")
        if "install.py" in joined:
            document = {
                "ok": True,
                "changed": False,
                "dry_run": True,
                "account": "mks",
                "paths": paths,
                "backup_manifest": backup_manifest,
                "safety_manifest": None,
                "transaction_state": "not_started",
            }
            return subprocess.CompletedProcess(
                command, 0, json.dumps(document).encode("utf-8"), b""
            )
        raise AssertionError(command)

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(
        qidi_plus4.subprocess,
        "run",
        lambda command, **_kwargs: subprocess.CompletedProcess(command, 0),
    )
    args = connection_args(
        "rollback-plr-hardening",
        confirm="ROLLBACK-PLR-HARDENING",
        backup_manifest=backup_manifest,
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
        service="klipper.service",
    )

    qidi_plus4.rollback_plr_hardening(args)

    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is True
    assert result["changed"] is False
    assert result["backup_manifest"] == backup_manifest
    assert not any("systemctl stop" in " ".join(call) for call in calls)


def test_rollback_partial_failure_preserves_both_transaction_handles(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    paths = canonical_plr_paths()
    transaction_id = "20260806T000000Z-rollback"
    backup_manifest = (
        "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-proof/backup-manifest.json"
    )
    safety_manifest = (
        f"/home/mks/scripts/plr/backups/plr-rollback-safety-{transaction_id}/safety-manifest.json"
    )
    installer_reads = 0
    monkeypatch.setattr(qidi_plus4, "_plr_transaction_id", lambda: transaction_id)
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi1"], "mks@qidi1"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])

    def fake_capture(
        command: list[str], input_data: bytes | None = None
    ) -> subprocess.CompletedProcess[bytes]:
        nonlocal installer_reads
        joined = " ".join(command)
        if "mktemp -d" in joined:
            return subprocess.CompletedProcess(command, 0, b"/tmp/qidi-plr-hardening.ROLL2\n", b"")
        if command[0] == "scp" or "systemctl stop" in joined:
            return subprocess.CompletedProcess(command, 0, b"", b"")
        if "systemctl is-active" in joined:
            return subprocess.CompletedProcess(command, 3, b"inactive\n", b"")
        if "install.py" in joined:
            installer_reads += 1
            document = {
                "ok": installer_reads == 1,
                "changed": True,
                "account": "mks",
                "paths": paths,
                "backup_manifest": backup_manifest,
                "safety_manifest": safety_manifest,
                "transaction_state": ("not_started" if installer_reads == 1 else "partial"),
                "applied": None,
            }
            if installer_reads > 1:
                document["error"] = "simulated incomplete safety restore"
            return subprocess.CompletedProcess(
                command,
                0 if installer_reads == 1 else 7,
                json.dumps(document).encode("utf-8"),
                b"rollback failed\n" if installer_reads > 1 else b"",
            )
        raise AssertionError(command)

    monkeypatch.setattr(qidi_plus4, "capture", fake_capture)
    monkeypatch.setattr(
        qidi_plus4.subprocess,
        "run",
        lambda command, **_kwargs: subprocess.CompletedProcess(command, 0),
    )
    args = connection_args(
        "rollback-plr-hardening",
        confirm="ROLLBACK-PLR-HARDENING",
        backup_manifest=backup_manifest,
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
        service="klipper.service",
    )

    with pytest.raises(SystemExit) as failure:
        qidi_plus4.rollback_plr_hardening(args)

    assert failure.value.code == 1
    result = json.loads(capsys.readouterr().out)
    assert result["phase"] == "apply"
    assert result["transaction_state"] == "partial"
    assert result["applied"] is None
    assert result["backup_manifest"] == backup_manifest
    assert result["safety_manifest"] == safety_manifest
    assert result["rollback"]["error"] == "simulated incomplete safety restore"


def test_plr_layout_rejects_paths_from_a_different_account() -> None:
    args = connection_args(
        "deploy-plr-hardening",
        printer_user="printer",
        klipper_dir="/home/mks/klipper",
        printer_data="/home/mks/printer_data",
        scripts_dir="/home/mks/scripts/plr",
        remote_python="/home/mks/klippy-env/bin/python",
    )

    with pytest.raises(SystemExit, match="must match printer account printer"):
        qidi_plus4._validated_plr_layout(args)


def test_plr_rollback_manifest_path_is_strict() -> None:
    valid = "/home/mks/scripts/plr/backups/plr-hardening-20260806T000000Z-abc/backup-manifest.json"
    assert qidi_plus4._validated_plr_backup_manifest(valid, "/home/mks/scripts/plr") == valid
    with pytest.raises(SystemExit, match="exact PLR installer"):
        qidi_plus4._validated_plr_backup_manifest(
            "/tmp/backup-manifest.json", "/home/mks/scripts/plr"
        )


def test_parser_accepts_exact_external_profile_directory(tmp_path: pathlib.Path) -> None:
    parser = qidi_plus4.create_parser()
    profile = tmp_path / "qidi2"

    args = parser.parse_args(
        [
            "render-config",
            "--profile-dir",
            str(profile),
            "--beacon-serial",
            BEACON_SERIAL,
            "--output",
            str(tmp_path / "rendered"),
        ]
    )

    assert args.func is qidi_plus4.render_config
    assert args.profile_dir == profile


def test_parser_preserves_bundled_profile_fallback(tmp_path: pathlib.Path) -> None:
    parser = qidi_plus4.create_parser()

    args = parser.parse_args(
        [
            "render-config",
            "--beacon-serial",
            BEACON_SERIAL,
            "--output",
            str(tmp_path / "rendered"),
        ]
    )

    assert args.profile == qidi_plus4.DEFAULT_CONFIG_PROFILE
    assert args.profile_dir is None


def test_host_tuning_helper_contains_persistent_safety_controls() -> None:
    helper = qidi_plus4.HOST_TUNING_HELPER.read_text(encoding="utf-8")

    assert "ensure_printer_idle" in helper
    assert "CPUAffinity=1 2" in helper
    assert "CPUAffinity=0 3" in helper
    assert "Requires=qidi-plus4-host-tuning.service" in helper
    assert "ExecStart=/bin/bash /usr/local/sbin/qidi-plus4-host-tuning apply-early" in helper
    assert (
        "ExecStartPost=+/bin/bash /usr/local/sbin/qidi-plus4-host-tuning "
        "apply-late --wait-seconds 60 --settle-seconds 60" in helper
    )
    assert "systemctl status --no-pager --full" in helper
    assert "journalctl --no-pager -u qidi-plus4-host-tuning.service" in helper
    assert "systemctl status --no-pager --full klipper.service" in helper
    assert "journalctl --no-pager -u klipper.service -n 80" in helper
    assert "systemctl is-failed --quiet qidi-plus4-host-tuning.service" in helper
    assert "'http://127.0.0.1:7125/server/info'" in helper
    assert "printer_state=klipper-inactive" in helper
    assert "/proc/tty/driver/serial" in helper
    assert "port_number=${tty#ttyS}" in helper
    assert "ttyS0:ff110000) irq=25" in helper
    assert "ttyS2:ff130000) irq=27" in helper
    assert "irq_affinity_is_writable ttyS2 ff130000" in helper
    assert "irq_affinity_is_writable ttyS0 ff110000" in helper
    assert "crowsnest.service" in helper
    assert "qidi-screen-bridge.service" in helper
    assert "set_irq_cpu ttyS2 ff130000 1" in helper
    assert "set_irq_cpu ttyS0 ff110000 2" in helper
    assert "systemctl mask irqbalance.service" in helper
    assert "systemctl mask ondemand.service" in helper
    assert "persistent_service_state=" in helper
    assert "klipper_service_state=" in helper
    assert "After=armbian-hardware-monitor.service armbian-hardware-optimize.service" in helper
    assert "settling_host_seconds=" in helper
    assert "waiting_for_klipper_tuning=90s" in helper


def test_tune_host_requires_exact_confirmation() -> None:
    args = connection_args("tune-host", confirm="yes")

    with pytest.raises(SystemExit, match="--confirm TUNE-HOST"):
        qidi_plus4.host_tuning(args)


def test_audit_streams_read_only_helper(monkeypatch: pytest.MonkeyPatch) -> None:
    calls: list[tuple[list[str], bytes | None]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi2"], "mks@qidi2"))
    monkeypatch.setattr(
        qidi_plus4,
        "run",
        lambda command, input_data=None: calls.append((command, input_data)),
    )

    qidi_plus4.host_tuning(connection_args("audit-host-tuning"))

    assert calls == [
        (
            ["ssh", "qidi2", "bash -s -- audit"],
            qidi_plus4.HOST_TUNING_HELPER.read_bytes(),
        )
    ]


def test_tune_host_uploads_installs_and_cleans_up(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    run_calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi2"], "mks@qidi2"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])
    monkeypatch.setattr(
        qidi_plus4,
        "run",
        lambda command, input_data=None: run_calls.append(command),
    )
    qidi_plus4.host_tuning(connection_args("tune-host", confirm="TUNE-HOST"))

    assert run_calls[0] == [
        "scp",
        str(qidi_plus4.HOST_TUNING_HELPER),
        "mks@qidi2:/tmp/qidi-host-tuning.sh",
    ]
    assert run_calls[1][:2] == ["ssh", "qidi2"]
    assert "trap 'rm -f /tmp/qidi-host-tuning.sh' EXIT" in run_calls[1][2]
    assert "sudo -n bash /tmp/qidi-host-tuning.sh install --printer-user mks" in run_calls[1][2]


def test_bootstrap_uploads_and_passes_host_tuning_helper(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    calls: list[list[str]] = []
    monkeypatch.setattr(qidi_plus4, "ssh_base", lambda _args: (["ssh", "qidi2"], "mks@qidi2"))
    monkeypatch.setattr(qidi_plus4, "scp_base", lambda _args: ["scp"])
    monkeypatch.setattr(
        qidi_plus4,
        "run",
        lambda command, input_data=None: calls.append(command),
    )
    args = connection_args(
        "bootstrap-host",
        confirm="BOOTSTRAP-HOST",
        klipper_ref="klipper-ref",
        moonraker_ref="moonraker-ref",
        katapult_ref="katapult-ref",
    )

    qidi_plus4.bootstrap_host(args)

    assert calls[0][1] == str(qidi_plus4.BOOTSTRAP_HELPER)
    assert calls[1][1] == str(qidi_plus4.HOST_TUNING_HELPER)
    assert "QIDI_HOST_TUNING_HELPER=/home/mks/qidi-host-tuning.sh" in calls[2][2]


def test_render_config_supports_external_profile_and_output(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "qidi-plus4-configs" / "printers" / "mainline-klipper-beacon"
    profile.mkdir(parents=True)
    (profile / "printer.cfg").write_text(
        "[include hardware.cfg]\n# CHANGE_ME_BEACON_SERIAL\n", encoding="utf-8"
    )
    output = tmp_path / "workspace" / "qidi2"

    qidi_plus4.render_config(render_args(profile, output))

    assert BEACON_SERIAL in (output / "printer.cfg").read_text(encoding="utf-8")
    metadata = json.loads((output / qidi_plus4.RENDER_METADATA_FILE).read_text(encoding="utf-8"))
    assert metadata["schema"] == qidi_plus4.RENDER_METADATA_SCHEMA
    assert metadata["managed_by"] == qidi_plus4.RENDER_METADATA_MANAGER
    assert metadata["profile"] == "mainline-klipper-beacon"


def test_render_force_refuses_unmanaged_directory(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "profile"
    profile.mkdir()
    (profile / "printer.cfg").write_text("[mcu]\n", encoding="utf-8")
    output = tmp_path / "existing"
    output.mkdir()
    sentinel = output / "keep-me.txt"
    sentinel.write_text("user data", encoding="utf-8")

    with pytest.raises(SystemExit, match="Refusing to replace unmanaged"):
        qidi_plus4.render_config(render_args(profile, output, force=True))

    assert sentinel.read_text(encoding="utf-8") == "user data"


def test_render_force_refuses_unrecognized_marker(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "profile"
    profile.mkdir()
    (profile / "printer.cfg").write_text("[mcu]\n", encoding="utf-8")
    output = tmp_path / "existing"
    output.mkdir()
    sentinel = output / "keep-me.txt"
    sentinel.write_text("user data", encoding="utf-8")
    (output / qidi_plus4.RENDER_METADATA_FILE).write_text(
        json.dumps(
            {
                "schema": qidi_plus4.RENDER_METADATA_SCHEMA,
                "managed_by": "someone-else",
                "profile": "qidi2",
                "beacon_serial": BEACON_SERIAL,
                "rendered_at_utc": "2026-07-14T00:00:00+00:00",
            }
        ),
        encoding="utf-8",
    )

    with pytest.raises(SystemExit, match="Refusing to replace unmanaged"):
        qidi_plus4.render_config(render_args(profile, output, force=True))

    assert sentinel.read_text(encoding="utf-8") == "user data"


def test_render_force_replaces_only_managed_directory(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "profile"
    profile.mkdir()
    source = profile / "printer.cfg"
    source.write_text("# first\n", encoding="utf-8")
    output = tmp_path / "rendered"
    qidi_plus4.render_config(render_args(profile, output))
    (output / "stale.cfg").write_text("stale\n", encoding="utf-8")
    source.write_text("# second\n", encoding="utf-8")

    qidi_plus4.render_config(render_args(profile, output, force=True))

    assert (output / "printer.cfg").read_text(encoding="utf-8") == "# second\n"
    assert not (output / "stale.cfg").exists()


def test_render_force_accepts_legacy_qidi_marker(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "profile"
    profile.mkdir()
    (profile / "printer.cfg").write_text("[mcu]\n", encoding="utf-8")
    output = tmp_path / "legacy"
    output.mkdir()
    (output / qidi_plus4.RENDER_METADATA_FILE).write_text(
        json.dumps(
            {
                "profile": "plus4-x7-v1.0-beacon",
                "beacon_serial": BEACON_SERIAL,
                "rendered_at_utc": "2026-07-14T00:00:00+00:00",
            }
        ),
        encoding="utf-8",
    )

    qidi_plus4.render_config(render_args(profile, output, force=True))

    metadata = json.loads((output / qidi_plus4.RENDER_METADATA_FILE).read_text(encoding="utf-8"))
    assert metadata["schema"] == qidi_plus4.RENDER_METADATA_SCHEMA


def test_failed_render_keeps_existing_managed_output(tmp_path: pathlib.Path) -> None:
    profile = tmp_path / "empty-profile"
    profile.mkdir()
    valid_profile = tmp_path / "valid-profile"
    valid_profile.mkdir()
    (valid_profile / "printer.cfg").write_text("# existing\n", encoding="utf-8")
    output = tmp_path / "rendered"
    qidi_plus4.render_config(render_args(valid_profile, output))

    with pytest.raises(SystemExit, match="No .cfg files"):
        qidi_plus4.render_config(render_args(profile, output, force=True))

    assert (output / "printer.cfg").read_text(encoding="utf-8") == "# existing\n"
