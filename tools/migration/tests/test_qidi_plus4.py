from __future__ import annotations

import argparse
import importlib.util
import pathlib

import pytest


MODULE_PATH = pathlib.Path(__file__).resolve().parents[1] / "qidi_plus4.py"
SPEC = importlib.util.spec_from_file_location("qidi_plus4", MODULE_PATH)
assert SPEC and SPEC.loader
qidi_plus4 = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(qidi_plus4)


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


def test_parser_exposes_host_tuning_commands() -> None:
    parser = qidi_plus4.create_parser()

    audit = parser.parse_args(["audit-host-tuning", "--printer", "qidi2"])
    tune = parser.parse_args(
        ["tune-host", "--printer", "qidi2", "--confirm", "TUNE-HOST"]
    )

    assert audit.func is qidi_plus4.host_tuning
    assert tune.func is qidi_plus4.host_tuning
    assert tune.confirm == "TUNE-HOST"


def test_host_tuning_helper_contains_persistent_safety_controls() -> None:
    helper = qidi_plus4.HOST_TUNING_HELPER.read_text(encoding="utf-8")

    assert "ensure_printer_idle" in helper
    assert "CPUAffinity=1 2" in helper
    assert "CPUAffinity=0 3" in helper
    assert "Requires=qidi-plus4-host-tuning.service" in helper
    assert (
        "ExecStart=/bin/bash /usr/local/sbin/qidi-plus4-host-tuning apply-early"
        in helper
    )
    assert (
        "ExecStartPost=+/bin/bash /usr/local/sbin/qidi-plus4-host-tuning "
        "apply-late --wait-seconds 60 --settle-seconds 60"
        in helper
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
    qidi_plus4.host_tuning(
        connection_args("tune-host", confirm="TUNE-HOST")
    )

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
