from __future__ import annotations

import ast
import importlib.util
import json
import os
import pathlib
import subprocess
import types

import pytest

HELPER_PATH = pathlib.Path(__file__).resolve().parents[1] / "upgrade-klippee-agent.py"
POSIX_ONLY = pytest.mark.skipif(os.name == "nt", reason="printer helper is POSIX-only")


def load_helper():
    specification = importlib.util.spec_from_file_location(
        "qidi_klippee_agent_upgrader", HELPER_PATH
    )
    assert specification and specification.loader
    module = importlib.util.module_from_spec(specification)
    specification.loader.exec_module(module)
    return module


def valid_source(version: str) -> bytes:
    return (
        '"""Klippee\'s dependency-light config sync client."""\n'
        f'CLI_VERSION = "{version}"\n'
    ).encode()


def test_upgrader_source_is_python37_and_does_not_execute_installed_cli() -> None:
    source = HELPER_PATH.read_text(encoding="utf-8")
    ast.parse(source, filename=str(HELPER_PATH), feature_version=(3, 7))
    assert 'CLI_PATH, "upgrade"' not in source
    assert '"--disable"' in source
    assert "os.replace(temporary, CLI_PATH)" in source


@POSIX_ONLY
def test_checked_parent_secures_only_the_fixed_owned_directory(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    directory = tmp_path / "bin"
    directory.mkdir()
    directory.chmod(0o777)
    monkeypatch.setattr(helper, "CLI_PARENT", str(directory))
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=os.getuid())
    )

    helper.checked_parent()

    assert directory.stat().st_mode & 0o777 == 0o755


@POSIX_ONLY
def test_checked_parent_rejects_an_unowned_directory_before_chmod(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    directory = tmp_path / "bin"
    directory.mkdir()
    directory.chmod(0o777)
    monkeypatch.setattr(helper, "CLI_PARENT", str(directory))
    monkeypatch.setattr(
        helper.pwd,
        "getpwnam",
        lambda _name: types.SimpleNamespace(pw_uid=os.getuid() + 1),
    )

    with pytest.raises(helper.UpgradeError, match="unexpected owner or type"):
        helper.checked_parent()

    assert directory.stat().st_mode & 0o777 == 0o777


@POSIX_ONLY
def test_safe_environment_is_an_allowlist(monkeypatch: pytest.MonkeyPatch) -> None:
    helper = load_helper()
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=1234)
    )
    monkeypatch.setenv("LD_PRELOAD", "/tmp/attacker.so")
    monkeypatch.setenv("HTTPS_PROXY", "https://attacker.invalid")

    assert helper.safe_environment() == {
        "PATH": "/usr/bin:/bin",
        "HOME": "/home/mks",
        "USER": "mks",
        "LOGNAME": "mks",
        "LANG": "C",
        "LC_ALL": "C",
        "XDG_RUNTIME_DIR": "/run/user/1234",
        "DBUS_SESSION_BUS_ADDRESS": "unix:path=/run/user/1234/bus",
    }


@POSIX_ONLY
def test_download_uses_only_fixed_https_curl_contract(
    monkeypatch: pytest.MonkeyPatch,
) -> None:
    helper = load_helper()
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=1234)
    )
    observed: dict[str, object] = {}

    def fake_run(command, **kwargs):
        observed["command"] = command
        observed["environment"] = kwargs["env"]
        return subprocess.CompletedProcess(
            command, 0, valid_source("2099.01.01"), b""
        )

    monkeypatch.setattr(helper.subprocess, "run", fake_run)
    artifact = helper.download_cli()

    command = observed["command"]
    assert command[0:5] == [
        "/usr/bin/curl", "--disable", "--fail", "--silent", "--show-error"
    ]
    assert ["--proto", "=https"] == command[5:7]
    assert command[-1] == "https://klippee.xyz/install/klippee.py"
    assert artifact["version"] == "2099.01.01"
    assert "HTTPS_PROXY" not in observed["environment"]


def managed_unit_content() -> str:
    return """[Unit]
Description=Klippee Moonraker integration agent
After=network-online.target

[Service]
Type=simple
ExecStart="/usr/bin/python3" "/home/mks/.local/bin/klippee" moonraker-agent
Environment="KLIPPEE_MOONRAKER_SOCKET=/home/mks/printer_data/comms/moonraker.sock"
Environment="KLIPPEE_STATE_DIR=/home/mks/.klippee"
Restart=on-failure
RestartSec=5

[Install]
WantedBy=default.target
"""


@POSIX_ONLY
def test_unit_validation_secures_exact_owned_unit_metadata(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    parent = tmp_path / "user"
    parent.mkdir()
    parent.chmod(0o777)
    unit = parent / "klippee-moonraker.service"
    unit.write_text(managed_unit_content(), encoding="utf-8")
    unit.chmod(0o666)
    monkeypatch.setattr(helper, "UNIT_PARENT", str(parent))
    monkeypatch.setattr(helper, "UNIT_PATH", str(unit))
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=os.getuid())
    )

    helper.read_unit()

    assert parent.stat().st_mode & 0o777 == 0o755
    assert unit.stat().st_mode & 0o777 == 0o600


@POSIX_ONLY
def test_unit_validation_does_not_chmod_unreviewed_content(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    unit = tmp_path / "klippee-moonraker.service"
    unit.write_text(managed_unit_content() + "ExecStartPre=/bin/false\n", encoding="utf-8")
    unit.chmod(0o666)
    monkeypatch.setattr(helper, "UNIT_PARENT", str(tmp_path))
    monkeypatch.setattr(helper, "UNIT_PATH", str(unit))
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=os.getuid())
    )

    with pytest.raises(helper.UpgradeError, match="directive count"):
        helper.read_unit()

    assert unit.stat().st_mode & 0o777 == 0o666


@POSIX_ONLY
def test_unit_validation_rejects_extra_actions_and_dropins(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    unit = tmp_path / "klippee-moonraker.service"
    unit.write_text(managed_unit_content(), encoding="utf-8")
    unit.chmod(0o600)
    monkeypatch.setattr(helper, "UNIT_PARENT", str(tmp_path))
    monkeypatch.setattr(helper, "UNIT_PATH", str(unit))
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=os.getuid())
    )
    monkeypatch.setattr(
        helper,
        "systemctl_property",
        lambda name: {
            "FragmentPath": str(unit),
            "DropInPaths": "",
            "NeedDaemonReload": "no",
        }[name],
    )
    helper.validate_unit()

    unit.write_text(
        managed_unit_content().replace(
            "Type=simple\n", "Type=simple\nExecStartPre=/bin/false\n"
        ),
        encoding="utf-8",
    )
    with pytest.raises(helper.UpgradeError, match="directive count"):
        helper.validate_unit()

    unit.write_text(managed_unit_content(), encoding="utf-8")
    monkeypatch.setattr(
        helper,
        "systemctl_property",
        lambda name: {
            "FragmentPath": str(unit),
            "DropInPaths": "/tmp/override.conf",
            "NeedDaemonReload": "no",
        }[name],
    )
    with pytest.raises(helper.UpgradeError, match="drop-ins"):
        helper.validate_unit()

    monkeypatch.setattr(
        helper,
        "systemctl_property",
        lambda name: {
            "FragmentPath": str(unit),
            "DropInPaths": "",
            "NeedDaemonReload": "yes",
        }[name],
    )
    with pytest.raises(helper.UpgradeError, match="unapplied"):
        helper.validate_unit()


@POSIX_ONLY
def test_process_validation_binds_pid_to_fixed_cli_and_user(
    monkeypatch: pytest.MonkeyPatch, tmp_path: pathlib.Path
) -> None:
    helper = load_helper()
    pid = 512
    process = tmp_path / str(pid)
    process.mkdir()
    (process / "cmdline").write_bytes(
        b"/usr/bin/python3\x00/home/mks/.local/bin/klippee\x00moonraker-agent\x00"
    )
    (process / "status").write_text(
        "Name:\tpython3\nUid:\t1234\t1234\t1234\t1234\n",
        encoding="utf-8",
    )
    os.symlink("/usr/bin/python3.7", process / "exe")
    monkeypatch.setattr(helper, "PROC_ROOT", str(tmp_path))
    monkeypatch.setattr(
        helper.pwd, "getpwnam", lambda _name: types.SimpleNamespace(pw_uid=1234)
    )
    helper.validate_agent_process(pid)

    (process / "cmdline").write_bytes(
        b"/usr/bin/python3\x00/home/mks/attacker.py\x00moonraker-agent\x00"
    )
    with pytest.raises(helper.UpgradeError, match="not the fixed Klippee agent"):
        helper.validate_agent_process(pid)


@POSIX_ONLY
def test_pre_mutation_failure_does_not_restart_agent(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    helper = load_helper()
    before = helper.validate_source(valid_source("2026.08.06.5"), "before")
    service = {"observed_state": "active", "state_exit": 0, "pid": 410}
    monkeypatch.setattr(helper, "read_cli", lambda: before)
    monkeypatch.setattr(helper, "validate_unit", lambda: None)
    monkeypatch.setattr(helper, "service_evidence", lambda: dict(service))
    monkeypatch.setattr(
        helper,
        "download_cli",
        lambda: (_ for _ in ()).throw(helper.UpgradeError("download failed")),
    )
    monkeypatch.setattr(
        helper,
        "run_systemctl",
        lambda *_args: pytest.fail("pre-mutation failure must not restart the agent"),
    )

    assert helper.main() == 1
    result = json.loads(capsys.readouterr().out)
    assert result["ok"] is False
    assert result["before_pid"] == result["after_pid"] == 410
    assert result["agent_restart_performed"] is False


@POSIX_ONLY
def test_atomic_failure_attempts_old_cli_rollback_before_recovery(
    monkeypatch: pytest.MonkeyPatch, capsys: pytest.CaptureFixture[str]
) -> None:
    helper = load_helper()
    before = helper.validate_source(valid_source("2026.08.06.5"), "before")
    replacement = helper.validate_source(valid_source("2026.08.06.6"), "after")
    service = {"observed_state": "active", "state_exit": 0, "pid": 410}
    monkeypatch.setattr(helper, "read_cli", lambda: before)
    monkeypatch.setattr(helper, "validate_unit", lambda: None)
    monkeypatch.setattr(helper, "service_evidence", lambda: dict(service))
    monkeypatch.setattr(helper, "download_cli", lambda: replacement)
    replacements: list[bytes] = []

    def fake_replace(source: bytes, _mode: int) -> None:
        replacements.append(source)
        if len(replacements) == 1:
            raise OSError("directory fsync failed after replace")

    monkeypatch.setattr(helper, "atomic_replace", fake_replace)
    monkeypatch.setattr(
        helper,
        "run_systemctl",
        lambda *_args: subprocess.CompletedProcess([], 0, "", ""),
    )
    monkeypatch.setattr(
        helper,
        "wait_for_service",
        lambda _pid: {"observed_state": "active", "state_exit": 0, "pid": 512},
    )

    assert helper.main() == 1
    result = json.loads(capsys.readouterr().out)
    assert replacements == [replacement["source"], before["source"]]
    assert result["ok"] is False
    assert result["changed"] is False
    assert result["agent_restart_performed"] is True
