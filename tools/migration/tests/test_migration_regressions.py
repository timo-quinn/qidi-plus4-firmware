from __future__ import annotations

import argparse
import hashlib
import pathlib
import shutil
import subprocess

import pytest

import qidi_plus4 as migration


def test_manifest_rejects_changed_image_before_transport(tmp_path, monkeypatch):
    names = ("plus4-mainboard-klipper.bin", "plus4-toolhead-klipper.bin",
             "plus4-toolhead-katapult.bin")
    manifest = [f"klipper_commit={migration.KLIPPER_REF}",
                f"katapult_commit={migration.KATAPULT_REF}"]
    for name in names:
        (tmp_path / name).write_bytes(b"original")
        manifest.append(f"{hashlib.sha256(b'original').hexdigest()}  {name}")
    (tmp_path / "BUILD-METADATA.txt").write_text("\n".join(manifest))
    assert migration.verify_build_metadata(tmp_path)["klipper_commit"] == migration.KLIPPER_REF
    (tmp_path / names[0]).write_bytes(b"changed")
    monkeypatch.setattr(migration, "ssh_base", lambda args: pytest.fail("transport started"))
    args = argparse.Namespace(confirm="BOOTSTRAP-HOST", klipper_ref=migration.KLIPPER_REF,
                              moonraker_ref=migration.MOONRAKER_REF,
                              katapult_ref=migration.KATAPULT_REF, artifacts=tmp_path)
    with pytest.raises(SystemExit, match="hash mismatch"):
        migration.bootstrap_host(args)


@pytest.mark.parametrize("ref", ["master", "v0.13.0", "214fdb2", "a" * 41])
def test_moving_or_abbreviated_bootstrap_refs_rejected(ref):
    with pytest.raises(argparse.ArgumentTypeError):
        migration.pinned_ref(ref)


def test_windows_wsl_build_keeps_source_paths_and_converts_output(monkeypatch, tmp_path):
    calls = []
    monkeypatch.setattr(migration, "require_command", lambda name: name)
    monkeypatch.setattr(migration, "run", lambda command: calls.append(command))
    args = argparse.Namespace(wsl_distro="Ubuntu", klipper_dir=pathlib.Path("/home/tim/klipper"),
                              katapult_dir=pathlib.Path("/home/tim/katapult"), output=tmp_path,
                              klipper_ref=migration.KLIPPER_REF, katapult_ref=migration.KATAPULT_REF)
    migration.build_firmware(args)
    command = calls[0]
    assert command[:5] == ["wsl", "-d", "Ubuntu", "--", "python3"]
    assert "/home/tim/klipper" in command
    assert command[-1] == migration.KATAPULT_REF
    assert migration.wsl_path(pathlib.Path("C:/Projects/build")) == "/mnt/c/Projects/build"


@pytest.mark.parametrize("ready", [False, True])
def test_smoke_test_requires_ready_mcus_and_runtime_audit(monkeypatch, ready):
    calls = []
    monkeypatch.setattr(migration, "ssh_base", lambda args: (["ssh", "printer"], "mks@printer"))
    monkeypatch.setattr(migration, "run", lambda command, input_data=None: calls.append(command))
    monkeypatch.setattr(migration.time, "sleep", lambda seconds: None)
    facts = {"printer_cfg": {"present": True, "sha256": migration.sha256(migration.SMOKE_TEST_CONFIG)},
             "moonraker": {"reachable": True, "klippy_state": "ready" if ready else "error",
                           "mcu_objects": ["mcu", "mcu toolhead"]}}
    monkeypatch.setattr(migration, "collect_facts", lambda args: (facts, ""))
    args = argparse.Namespace(data_dir="/home/mks/printer_data", user="plab", printer_user="mks")
    if ready:
        migration.smoke_test(args)
        assert calls[-1][-1] == "bash -s -- audit"
    else:
        with pytest.raises(SystemExit, match="Smoke test failed"):
            migration.smoke_test(args)
        assert len(calls) == 1


def test_early_audit_passes_without_uart_affinity_but_runtime_audit_fails():
    # Run only read-only audit functions with synthetic sysfs and systemctl.
    # The test never installs units, changes affinity or accesses the printer.
    source = migration.HOST_TUNING_HELPER.read_text().split('action="${1:-}"')[0]
    harness = """
fixture=$(mktemp -d)
trap 'rm -rf "$fixture"' EXIT
mkdir -p "$fixture/cpu/cpufreq/policy0"
printf '0-3' >"$fixture/cpu/online"
printf performance >"$fixture/cpu/cpufreq/policy0/scaling_governor"
"""
    source = source.replace("/sys/devices/system/cpu", '${fixture}/cpu')
    # Redirection with variable expansion must use quotes, as the real paths do.
    source = source.replace("$(< ${fixture}/cpu/online)", '$(< "$fixture/cpu/online")')
    harness += source + """
validate_host() { return 0; }
irq_for_tty() { return 1; }
service_cpu_list() { echo inactive; }
systemctl() {
    case "$*" in
        'is-active klipper.service') echo inactive ;;
        'is-active qidi-plus4-host-tuning.service') echo active ;;
        'is-enabled --quiet qidi-plus4-host-tuning.service') return 0 ;;
        *) return 1 ;;
    esac
}
audit_tuning early
if audit_tuning runtime; then exit 42; fi
"""
    if shutil.which("wsl"):
        command = ["wsl", "-d", "Ubuntu", "--", "bash", "-s"]
    elif shutil.which("bash"):
        command = ["bash", "-s"]
    else:
        pytest.skip("bash is required for the read-only shell audit test")
    result = subprocess.run(command, input=harness.encode(), capture_output=True, timeout=20)
    assert result.returncode == 0, result.stderr.decode()
    assert b"result=early-tuned" in result.stdout
    assert b"result=not-tuned" in result.stdout


@pytest.mark.parametrize("dump_size", [12, 65536])
def test_toolhead_erase_requires_verified_workstation_dump(tmp_path, monkeypatch, dump_size):
    image = tmp_path / "katapult.bin"
    image.write_bytes(b"image")
    calls = []
    monkeypatch.setattr(migration, "stage", lambda args, kind: (["ssh", "printer"], "/helper", "/image"))
    monkeypatch.setattr(migration, "run", lambda command: calls.append(command))
    monkeypatch.setattr(migration, "capture", lambda command: subprocess.CompletedProcess(
        command, 0, b"\xff" * dump_size, b""))
    args = argparse.Namespace(command="flash-toolhead-katapult", confirm="ERASE-TOOLHEAD",
                              user="plab", printer_user="mks", image=image,
                              remote_directory="/home/mks/migration", backup_output=tmp_path)
    if dump_size != 65536:
        with pytest.raises(SystemExit, match="refusing erase"):
            migration.remote_action(args)
        assert len(calls) == 1 and "backup-toolhead" in calls[0][-1]
    else:
        migration.remote_action(args)
        dump = next(tmp_path.glob("toolhead-before-erase-*.bin"))
        digest = migration.sha256(dump)
        assert digest in calls[-1][-1]
        assert "flash-toolhead-katapult" in calls[-1][-1]
        assert digest in dump.with_suffix(".bin.sha256").read_text()


def test_commissioning_render_excludes_source_calibration_and_production(tmp_path):
    profile = tmp_path / "profile"
    profile.mkdir()
    (profile / "printer.cfg").write_text("[include production.cfg]\n[input_shaper]\nshaper_freq_x: 76.4\n")
    (profile / "hardware.cfg").write_text("[mcu]\nserial: /dev/ttyS2\n[mcu U_1]\nserial: /dev/ttyS0\n")
    (profile / "beacon.cfg").write_text("[beacon]\nserial: CHANGE_ME_BEACON_SERIAL\naccel_axes_map: -y, x, z\n")
    destination = tmp_path / "output"
    migration.render_config(argparse.Namespace(profile_dir=profile, beacon_serial="/dev/serial/by-id/usb-Beacon_TEST",
                                              output=destination, force=False, commissioning=True))
    config = (destination / "printer.cfg").read_text()
    assert "[include hardware.cfg]" in config and "[include beacon.cfg]" in config
    assert "[include production.cfg]" not in config and "shaper_freq" not in config
    assert "control: watermark" in config and "pid_K" not in config
    assert "pressure_advance: 0" in config
    assert "accel_axes_map: x, y, z" in (destination / "beacon.cfg").read_text()


def test_image_alias_cannot_silently_download_an_older_kernel(tmp_path, monkeypatch):
    class Response:
        def __enter__(self):
            return self

        def __exit__(self, *args):
            return None

        def geturl(self):
            return "https://example.invalid/Armbian_26.8.1_Qidi-x6_trixie_current_6.18.44_minimal.img.xz"

    monkeypatch.setattr(migration.urllib.request, "urlopen", lambda *args, **kwargs: Response())
    monkeypatch.setattr(migration, "download_file", lambda *args: pytest.fail("image download began"))
    args = argparse.Namespace(list_only=False, output=tmp_path, minimum_kernel="6.18.54")
    with pytest.raises(SystemExit, match="older than required"):
        migration.armbian_image(args)
