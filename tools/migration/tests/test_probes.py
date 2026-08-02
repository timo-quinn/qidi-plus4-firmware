from __future__ import annotations

import copy
import hashlib
import json
import pathlib

import pytest

import probes


REMOTE_HELPER = pathlib.Path(__file__).resolve().parents[1] / "qidi-plus4-remote.sh"
SMOKE_TEST_CONFIG = pathlib.Path(__file__).resolve().parents[1] / "smoke-test-printer.cfg"
SMOKE_SHA = hashlib.sha256(SMOKE_TEST_CONFIG.read_bytes()).hexdigest()
CONTEXT = probes.Context(smoke_test_sha256=SMOKE_SHA)


def migrated_facts() -> dict:
    """A fully migrated, healthy Plus4 running a real configuration."""
    return {
        "schema": 1,
        "collected_at_utc": "2026-07-31T02:00:00+00:00",
        "hostname": "qidi2",
        "data_dir": "/home/mks/printer_data",
        "home": "/home/mks",
        "os_release": {"ID": "debian", "PRETTY_NAME": "Armbian 25.5 trixie"},
        "passwordless_sudo": True,
        "services": {
            "klipper": "active",
            "moonraker": "active",
            "makerbase-client": "not-found",
            "qidi-plus4-host-tuning": "active",
        },
        "services_enabled": {
            "klipper": "enabled",
            "moonraker": "enabled",
            "makerbase-client": "not-found",
            "qidi-plus4-host-tuning": "enabled",
        },
        "serial_getty": {"ttyS0": "masked", "ttyS2": "masked"},
        "serial_devices": {
            "/dev/ttyS0": {"present": True, "users": [900]},
            "/dev/ttyS2": {"present": True, "users": [900]},
        },
        "udev_rule": True,
        "klippy_env": True,
        "bootstrap_receipt": {
            "present": True,
            "installed_at_utc": "2026-07-20T10:00:00Z",
            "klipper_commit": "a" * 40,
            "moonraker_commit": "b" * 40,
            "katapult_commit": "c" * 40,
            "qidi_host_tuning_version": "3",
        },
        "checkouts": {
            "klipper": {"present": True, "head": "a" * 40},
            "moonraker": {"present": True, "head": "b" * 40},
            "katapult": {"present": True, "head": "c" * 40},
        },
        "printer_cfg": {
            "present": True,
            "path": "/home/mks/printer_data/config/printer.cfg",
            "size": 4096,
            "sha256": "d" * 64,
            "mcu_sections": ["mcu", "mcu toolhead"],
            "serials": ["/dev/ttyS0", "/dev/ttyS2"],
        },
        "moonraker": {
            "reachable": True,
            "klippy_state": "ready",
            "klippy_message": "Printer is ready",
            "mcu_objects": ["mcu", "mcu toolhead"],
        },
        "stock_markers": {"hid_flash": [], "full_flash_images": []},
        "errors": [],
    }


def stock_facts() -> dict:
    """An untouched printer still running stock QIDI firmware."""
    return {
        "schema": 1,
        "collected_at_utc": "2026-07-31T02:00:00+00:00",
        "hostname": "qidi1",
        "data_dir": "/home/mks/printer_data",
        "home": "/home/mks",
        "passwordless_sudo": True,
        "services": {
            "klipper": "active",
            "moonraker": "active",
            "makerbase-client": "active",
            "qidi-plus4-host-tuning": "not-found",
        },
        "services_enabled": {
            "klipper": "enabled",
            "moonraker": "enabled",
            "makerbase-client": "enabled",
            "qidi-plus4-host-tuning": "not-found",
        },
        "serial_getty": {"ttyS0": "disabled", "ttyS2": "disabled"},
        "udev_rule": False,
        "klippy_env": False,
        "bootstrap_receipt": {"present": False},
        "checkouts": {
            "klipper": {"present": False, "head": None},
            "moonraker": {"present": False, "head": None},
            "katapult": {"present": False, "head": None},
        },
        "printer_cfg": {
            "present": True,
            "size": 8192,
            "sha256": "e" * 64,
            "mcu_sections": ["mcu"],
            "serials": ["/dev/ttyS0"],
        },
        "moonraker": {"reachable": False},
        "stock_markers": {"hid_flash": ["/root/hid-flash"], "full_flash_images": []},
        "errors": [],
    }


def status_of(results, probe_id: str) -> str:
    return next(result.status for result in results if result.probe == probe_id)


def detail_of(results, probe_id: str) -> str:
    return next(result.detail for result in results if result.probe == probe_id)


# --------------------------------------------------------------------------
# The core safety invariant.
# --------------------------------------------------------------------------


@pytest.mark.parametrize("probe", probes.PROBES, ids=lambda probe: probe.id)
def test_no_probe_claims_a_verdict_without_facts(probe: probes.Probe) -> None:
    """An empty fact set must never produce a confident answer.

    This is the property the whole layer rests on: absent evidence has to read
    as indeterminate, because treating it as unsatisfied re-runs destructive
    stages and treating it as satisfied skips stages that never ran.
    """
    result = probe.evaluate({}, CONTEXT)

    assert result.status == probes.INDETERMINATE


@pytest.mark.parametrize("probe", probes.PROBES, ids=lambda probe: probe.id)
def test_probes_tolerate_arbitrary_missing_branches(probe: probes.Probe) -> None:
    """Dropping any single top-level fact must not raise."""
    facts = migrated_facts()
    for key in list(facts):
        reduced = copy.deepcopy(facts)
        reduced.pop(key)
        result = probe.evaluate(reduced, CONTEXT)
        assert result.status in (
            probes.SATISFIED, probes.UNSATISFIED, probes.INDETERMINATE
        )


def test_missing_fact_is_not_read_as_a_negative() -> None:
    facts = migrated_facts()
    del facts["bootstrap_receipt"]

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "bootstrap.receipt") == probes.INDETERMINATE
    assert "did not report" in detail_of(results, "bootstrap.receipt")


def test_a_false_fact_is_distinguishable_from_an_absent_one() -> None:
    present = migrated_facts()
    present["udev_rule"] = False
    absent = migrated_facts()
    del absent["udev_rule"]

    assert status_of(probes.evaluate(present, CONTEXT), "bootstrap.uart-claimed") == (
        probes.UNSATISFIED
    )
    assert status_of(probes.evaluate(absent, CONTEXT), "bootstrap.uart-claimed") == (
        probes.INDETERMINATE
    )


# --------------------------------------------------------------------------
# Stage recognition.
# --------------------------------------------------------------------------


def test_migrated_printer_satisfies_the_bootstrap_stages() -> None:
    results = probes.evaluate(migrated_facts(), CONTEXT)

    assert status_of(results, "host.reachable") == probes.SATISFIED
    assert status_of(results, "bootstrap.receipt") == probes.SATISFIED
    assert status_of(results, "bootstrap.sources") == probes.SATISFIED
    assert status_of(results, "bootstrap.services") == probes.SATISFIED
    assert status_of(results, "bootstrap.uart-claimed") == probes.SATISFIED
    assert status_of(results, "host-tuning.installed") == probes.SATISFIED
    assert status_of(results, "config.installed") == probes.SATISFIED
    assert status_of(results, "mcu.online") == probes.SATISFIED
    assert status_of(results, "host.stock-client") == probes.UNSATISFIED


def test_stock_printer_reports_the_inverse() -> None:
    results = probes.evaluate(stock_facts(), CONTEXT)

    assert status_of(results, "host.stock-client") == probes.SATISFIED
    assert status_of(results, "bootstrap.receipt") == probes.UNSATISFIED
    assert status_of(results, "bootstrap.sources") == probes.UNSATISFIED
    assert status_of(results, "bootstrap.uart-claimed") == probes.UNSATISFIED
    assert status_of(results, "host-tuning.installed") == probes.UNSATISFIED
    # Moonraker is present on stock firmware but is not queried successfully
    # here, so MCU state is unknown rather than negative.
    assert status_of(results, "mcu.online") == probes.INDETERMINATE


def test_smoke_test_config_is_recognised_by_digest() -> None:
    facts = migrated_facts()
    facts["printer_cfg"]["sha256"] = SMOKE_SHA

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "config.smoke-test") == probes.SATISFIED
    # The smoke-test config must not also count as a real configuration.
    assert status_of(results, "config.installed") == probes.UNSATISFIED


def test_bootstrap_placeholder_config_is_not_a_real_configuration() -> None:
    facts = migrated_facts()
    facts["printer_cfg"]["size"] = 0

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "config.installed") == probes.UNSATISFIED
    assert "placeholder" in detail_of(results, "config.installed")


def test_single_mcu_config_is_incomplete_for_a_plus4() -> None:
    facts = migrated_facts()
    facts["printer_cfg"]["mcu_sections"] = ["mcu"]

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "config.installed") == probes.UNSATISFIED


def test_unhashable_smoke_config_does_not_fabricate_a_verdict() -> None:
    results = probes.evaluate(migrated_facts(), probes.Context(smoke_test_sha256=None))

    assert status_of(results, "config.smoke-test") == probes.INDETERMINATE


# --------------------------------------------------------------------------
# MCU state, which is the most safety-sensitive judgement.
# --------------------------------------------------------------------------


def test_klippy_shutdown_is_a_negative_with_its_reason() -> None:
    facts = migrated_facts()
    facts["moonraker"]["klippy_state"] = "shutdown"
    facts["moonraker"]["klippy_message"] = "MCU 'toolhead' is not responding\nmore"

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "mcu.online") == probes.UNSATISFIED
    assert "not responding" in detail_of(results, "mcu.online")


def test_klippy_startup_is_indeterminate_not_negative() -> None:
    facts = migrated_facts()
    facts["moonraker"]["klippy_state"] = "startup"

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "mcu.online") == probes.INDETERMINATE


def test_unreachable_moonraker_never_implies_dead_mcus() -> None:
    facts = migrated_facts()
    facts["moonraker"] = {"reachable": False}

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "mcu.online") == probes.INDETERMINATE


def test_ready_klippy_with_one_mcu_is_incomplete() -> None:
    facts = migrated_facts()
    facts["moonraker"]["mcu_objects"] = ["mcu"]

    results = probes.evaluate(facts, CONTEXT)

    assert status_of(results, "mcu.online") == probes.UNSATISFIED


# --------------------------------------------------------------------------
# Transport failure, which is the expected state mid-migration.
# --------------------------------------------------------------------------


def test_unreachable_printer_yields_a_complete_indeterminate_report() -> None:
    results = probes.unreachable("ssh exited 255: connection refused")

    assert len(results) == len(probes.PROBES)
    assert {result.status for result in results} == {probes.INDETERMINATE}
    assert all("connection refused" in result.detail for result in results)


def test_report_is_json_serialisable_when_unreachable() -> None:
    results = probes.unreachable("host is down")

    document = probes.report("qidi2", None, results, reachable=False)

    assert json.loads(json.dumps(document))["reachable"] is False
    assert document["summary"] == {
        probes.SATISFIED: 0,
        probes.UNSATISFIED: 0,
        probes.INDETERMINATE: len(probes.PROBES),
    }


def test_report_round_trips_evidence_containing_missing_facts() -> None:
    facts = migrated_facts()
    del facts["udev_rule"]

    results = probes.evaluate(facts, CONTEXT)
    document = probes.report("qidi2", facts, results, reachable=True)

    # MISSING is a sentinel object; it must not leak into the JSON document.
    encoded = json.dumps(document)
    assert "<missing>" not in encoded
    assert json.loads(encoded)["summary"][probes.INDETERMINATE] >= 1


# --------------------------------------------------------------------------
# Selection and registry.
# --------------------------------------------------------------------------


@pytest.mark.parametrize("facts", [migrated_facts(), stock_facts()],
                         ids=["migrated", "stock"])
def test_fact_keys_never_contain_dots(facts: dict) -> None:
    """Dotted paths are split on ".", so a dotted key would be unaddressable.

    Keying systemd template units by their full unit name silently reported a
    satisfied stage as indeterminate, which is how this constraint was found.
    """
    def walk(node: object, trail: str = "") -> None:
        if not isinstance(node, dict):
            return
        for key, value in node.items():
            assert "." not in key, f"dotted fact key at {trail}{key}"
            walk(value, f"{trail}{key}.")

    walk(facts)


def test_probe_ids_are_unique() -> None:
    ids = probes.probe_ids()

    assert len(ids) == len(set(ids))


def test_select_rejects_an_unknown_probe() -> None:
    with pytest.raises(KeyError, match="bootstrap.nonexistent"):
        probes.select(["bootstrap.nonexistent"])


def test_select_narrows_evaluation() -> None:
    results = probes.evaluate(migrated_facts(), CONTEXT, ids=["mcu.online"])

    assert [result.probe for result in results] == ["mcu.online"]


def test_every_probe_declares_a_stage() -> None:
    assert all(probe.stage and probe.description for probe in probes.PROBES)


# --------------------------------------------------------------------------
# The remote collector must stay in step with what the probes read.
# --------------------------------------------------------------------------


def test_remote_helper_exposes_the_probe_verb() -> None:
    helper = REMOTE_HELPER.read_text(encoding="utf-8")

    assert "probe) probe " in helper
    assert "{audit|probe|" in helper


@pytest.mark.parametrize("key", [
    "bootstrap_receipt", "checkouts", "printer_cfg", "serial_getty",
    "udev_rule", "klippy_env", "services_enabled", "moonraker", "stock_markers",
])
def test_remote_helper_collects_every_fact_group_the_probes_read(key: str) -> None:
    helper = REMOTE_HELPER.read_text(encoding="utf-8")

    assert f'"{key}"' in helper


def test_remote_helper_queries_units_individually() -> None:
    """Batched systemctl output is positional and misaligns on unknown units."""
    helper = REMOTE_HELPER.read_text(encoding="utf-8")

    assert '["systemctl", verb, unit]' in helper
    assert '["systemctl", verb, *units]' not in helper
