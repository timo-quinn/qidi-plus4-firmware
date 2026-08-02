#!/usr/bin/env python3
"""Migration-stage probes for the QIDI Plus4 mainline migration.

`qidi-plus4-remote.sh probe` collects observations from a printer and prints
them as JSON. This module turns those observations into per-stage judgements.

The split is deliberate. Collection needs hardware; evaluation does not, so
every rule below is unit-testable against recorded fixtures.

Three outcomes are possible, and the distinction between them is load-bearing:

    satisfied       the stage's effect is present on the machine
    unsatisfied     the stage's effect is definitively absent
    indeterminate   the facts needed to decide were not available

`indeterminate` must never be collapsed into either neighbour. Reading it as
`unsatisfied` re-runs a stage that may be destructive; reading it as
`satisfied` skips a stage that never ran. It means "ask the operator", and
callers are expected to stop rather than guess. Because of that, every rule
here resolves the facts it needs up front and returns `indeterminate` when any
of them is missing, rather than treating an absent fact as a negative answer.
"""

from __future__ import annotations

import dataclasses
import hashlib
import pathlib
from typing import Any, Callable, Iterable, Sequence


SCRIPT_DIR = pathlib.Path(__file__).resolve().parent
DEFAULT_SMOKE_TEST_CONFIG = SCRIPT_DIR / "smoke-test-printer.cfg"

SCHEMA_VERSION = 1

SATISFIED = "satisfied"
UNSATISFIED = "unsatisfied"
INDETERMINATE = "indeterminate"


class _Missing:
    """Sentinel for a fact the printer did not report."""

    def __repr__(self) -> str:
        return "<missing>"

    def __bool__(self) -> bool:
        return False


MISSING = _Missing()


def lookup(facts: Any, path: str) -> Any:
    """Resolve a dotted path, returning MISSING rather than a falsy default.

    A fact that is present and `False` must stay distinguishable from a fact
    that was never collected, so this never substitutes `None` for absence.

    Fact keys may not contain dots, since the path is split on them. The
    collector keys systemd template units by tty name for this reason.
    """
    node = facts
    for key in path.split("."):
        if not isinstance(node, dict) or key not in node:
            return MISSING
        node = node[key]
    return node


def _resolve(facts: Any, *paths: str) -> tuple[list[Any], list[str]]:
    values = [lookup(facts, path) for path in paths]
    missing = [path for path, value in zip(paths, values) if value is MISSING]
    return values, missing


@dataclasses.dataclass(frozen=True)
class ProbeResult:
    probe: str
    stage: str
    status: str
    detail: str
    evidence: dict[str, Any] = dataclasses.field(default_factory=dict)

    def as_dict(self) -> dict[str, Any]:
        return {
            "probe": self.probe,
            "stage": self.stage,
            "status": self.status,
            "detail": self.detail,
            "evidence": {key: (None if value is MISSING else value)
                         for key, value in self.evidence.items()},
        }


@dataclasses.dataclass(frozen=True)
class Context:
    """Local knowledge a probe needs in order to interpret remote facts."""

    smoke_test_sha256: str | None = None

    @classmethod
    def load(cls, smoke_test_config: pathlib.Path | None = None) -> "Context":
        path = smoke_test_config or DEFAULT_SMOKE_TEST_CONFIG
        digest = None
        if path.is_file():
            # .gitattributes pins *.cfg to eol=lf, so the working-tree bytes are
            # exactly the bytes scp delivers and the digests compare directly.
            digest = hashlib.sha256(path.read_bytes()).hexdigest()
        return cls(smoke_test_sha256=digest)


Evaluator = Callable[[Any, Context], ProbeResult]


@dataclasses.dataclass(frozen=True)
class Probe:
    id: str
    stage: str
    description: str
    evaluate: Evaluator


def _result(probe: Probe, status: str, detail: str,
            evidence: dict[str, Any] | None = None) -> ProbeResult:
    return ProbeResult(probe.id, probe.stage, status, detail, evidence or {})


def _evidence(facts: Any, *paths: str) -> dict[str, Any]:
    return {path: lookup(facts, path) for path in paths}


def _needs(probe: Probe, facts: Any, *paths: str) -> ProbeResult | None:
    """Return an indeterminate result when any required fact is absent."""
    _, missing = _resolve(facts, *paths)
    if missing:
        return _result(
            probe, INDETERMINATE,
            f"printer did not report: {', '.join(missing)}",
            _evidence(facts, *paths),
        )
    return None


# --------------------------------------------------------------------------
# Individual probes.
# --------------------------------------------------------------------------


def _eval_reachable(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["host.reachable"]
    collected = lookup(facts, "collected_at_utc")
    if collected is MISSING:
        return _result(probe, INDETERMINATE,
                       "no facts were collected from the printer")
    return _result(probe, SATISFIED, f"facts collected at {collected}",
                   _evidence(facts, "hostname", "collected_at_utc"))


def _eval_stock_client(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["host.stock-client"]
    paths = ("services.makerbase-client", "services_enabled.makerbase-client")
    if (blocked := _needs(probe, facts, *paths)) is not None:
        return blocked
    active, enabled = (lookup(facts, path) for path in paths)
    evidence = _evidence(facts, *paths)
    if active == "active" or enabled in ("enabled", "enabled-runtime", "static"):
        return _result(probe, SATISFIED,
                       "stock QIDI makerbase-client service is still installed",
                       evidence)
    if active == "not-found" and enabled == "not-found":
        return _result(probe, UNSATISFIED,
                       "stock QIDI makerbase-client service is absent", evidence)
    return _result(probe, UNSATISFIED,
                   f"makerbase-client is present but inactive ({active})", evidence)


def _eval_bootstrap_receipt(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["bootstrap.receipt"]
    if (blocked := _needs(probe, facts, "bootstrap_receipt.present")) is not None:
        return blocked
    evidence = _evidence(
        facts,
        "bootstrap_receipt.present", "bootstrap_receipt.installed_at_utc",
        "bootstrap_receipt.klipper_commit", "bootstrap_receipt.moonraker_commit",
        "bootstrap_receipt.katapult_commit",
    )
    if lookup(facts, "bootstrap_receipt.present") is True:
        stamp = lookup(facts, "bootstrap_receipt.installed_at_utc")
        detail = "host bootstrap receipt present"
        if stamp is not MISSING:
            detail += f", written {stamp}"
        return _result(probe, SATISFIED, detail, evidence)
    return _result(probe, UNSATISFIED,
                   "no mainline-bootstrap.txt receipt on the printer", evidence)


def _eval_bootstrap_sources(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["bootstrap.sources"]
    names = ("klipper", "moonraker", "katapult")
    paths = tuple(f"checkouts.{name}.present" for name in names)
    if (blocked := _needs(probe, facts, *paths)) is not None:
        return blocked
    evidence = _evidence(
        facts, *paths, *(f"checkouts.{name}.head" for name in names)
    )
    absent = [name for name in names
              if lookup(facts, f"checkouts.{name}.present") is not True]
    if not absent:
        return _result(probe, SATISFIED,
                       "klipper, moonraker and katapult checkouts are present",
                       evidence)
    return _result(probe, UNSATISFIED,
                   f"missing upstream checkouts: {', '.join(absent)}", evidence)


def _eval_bootstrap_services(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["bootstrap.services"]
    paths = ("services_enabled.klipper", "services_enabled.moonraker")
    if (blocked := _needs(probe, facts, *paths)) is not None:
        return blocked
    evidence = _evidence(facts, *paths, "services.klipper", "services.moonraker")
    installed = ("enabled", "enabled-runtime", "static", "indirect")
    absent = [path.rsplit(".", 1)[1] for path in paths
              if lookup(facts, path) not in installed]
    if not absent:
        return _result(probe, SATISFIED,
                       "klipper and moonraker system services are installed",
                       evidence)
    return _result(probe, UNSATISFIED,
                   f"service not installed: {', '.join(absent)}", evidence)


def _eval_bootstrap_uart(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["bootstrap.uart-claimed"]
    ttys = ("ttyS0", "ttyS2")
    gettys = tuple(f"serial_getty.{tty}" for tty in ttys)
    if (blocked := _needs(probe, facts, *gettys, "udev_rule")) is not None:
        return blocked
    evidence = _evidence(facts, *gettys, "udev_rule")
    # bootstrap-mainline.sh masks both login consoles and installs the dialout
    # udev rule; a console still holding a UART starves the MCU link.
    unmasked = [tty for tty in ttys
                if lookup(facts, f"serial_getty.{tty}")
                not in ("masked", "masked-runtime")]
    if unmasked or lookup(facts, "udev_rule") is not True:
        reasons = []
        if unmasked:
            reasons.append(f"serial console still enabled on {', '.join(unmasked)}")
        if lookup(facts, "udev_rule") is not True:
            reasons.append("99-qidi-uarts.rules is absent")
        return _result(probe, UNSATISFIED, "; ".join(reasons), evidence)
    return _result(probe, SATISFIED,
                   "both MCU UARTs are masked from getty and owned by dialout",
                   evidence)


def _eval_host_tuning(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["host-tuning.installed"]
    path = "services_enabled.qidi-plus4-host-tuning"
    if (blocked := _needs(probe, facts, path)) is not None:
        return blocked
    evidence = _evidence(facts, path, "services.qidi-plus4-host-tuning",
                         "bootstrap_receipt.qidi_host_tuning_version")
    if lookup(facts, path) in ("enabled", "enabled-runtime", "static"):
        version = lookup(facts, "bootstrap_receipt.qidi_host_tuning_version")
        detail = "host tuning service is installed"
        if version is not MISSING:
            detail += f" (recorded version {version})"
        return _result(probe, SATISFIED, detail, evidence)
    return _result(probe, UNSATISFIED,
                   "qidi-plus4-host-tuning.service is not installed", evidence)


def _eval_smoke_config(facts: Any, context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["config.smoke-test"]
    if context.smoke_test_sha256 is None:
        return _result(probe, INDETERMINATE,
                       "local smoke-test-printer.cfg could not be hashed")
    if (blocked := _needs(probe, facts, "printer_cfg.present")) is not None:
        return blocked
    evidence = _evidence(facts, "printer_cfg.present", "printer_cfg.sha256")
    evidence["expected_sha256"] = context.smoke_test_sha256
    if lookup(facts, "printer_cfg.present") is not True:
        return _result(probe, UNSATISFIED, "no printer.cfg is installed", evidence)
    digest = lookup(facts, "printer_cfg.sha256")
    if digest is MISSING:
        return _result(probe, INDETERMINATE,
                       "printer.cfg is present but was not hashed", evidence)
    if digest == context.smoke_test_sha256:
        return _result(probe, SATISFIED,
                       "the inert smoke-test printer.cfg is installed", evidence)
    return _result(probe, UNSATISFIED,
                   "printer.cfg is not the inert smoke-test configuration",
                   evidence)


def _eval_config_installed(facts: Any, context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["config.installed"]
    if (blocked := _needs(probe, facts, "printer_cfg.present")) is not None:
        return blocked
    evidence = _evidence(facts, "printer_cfg.present", "printer_cfg.size",
                         "printer_cfg.sha256", "printer_cfg.mcu_sections")
    if lookup(facts, "printer_cfg.present") is not True:
        return _result(probe, UNSATISFIED, "no printer.cfg is installed", evidence)
    # bootstrap-mainline.sh touches an empty printer.cfg, so presence alone
    # proves nothing about a real configuration.
    size = lookup(facts, "printer_cfg.size")
    if size is not MISSING and size == 0:
        return _result(probe, UNSATISFIED,
                       "printer.cfg is the empty placeholder left by bootstrap",
                       evidence)
    digest = lookup(facts, "printer_cfg.sha256")
    if context.smoke_test_sha256 is not None and digest == context.smoke_test_sha256:
        return _result(probe, UNSATISFIED,
                       "printer.cfg is still the inert smoke-test configuration",
                       evidence)
    sections = lookup(facts, "printer_cfg.mcu_sections")
    if isinstance(sections, list) and len(sections) < 2:
        return _result(probe, UNSATISFIED,
                       f"printer.cfg declares {len(sections)} mcu section(s); "
                       "the Plus4 needs both mainboard and toolhead", evidence)
    return _result(probe, SATISFIED,
                   "a non-placeholder printer.cfg with both MCUs is installed",
                   evidence)


def _eval_mcu_online(facts: Any, _context: Context) -> ProbeResult:
    probe = _PROBE_INDEX["mcu.online"]
    if (blocked := _needs(probe, facts, "moonraker.reachable")) is not None:
        return blocked
    evidence = _evidence(facts, "moonraker.reachable", "moonraker.klippy_state",
                         "moonraker.klippy_message", "moonraker.mcu_objects")
    if lookup(facts, "moonraker.reachable") is not True:
        return _result(probe, INDETERMINATE,
                       "Moonraker did not answer, so MCU state is unknown",
                       evidence)
    state = lookup(facts, "moonraker.klippy_state")
    if state is MISSING:
        return _result(probe, INDETERMINATE,
                       "Moonraker answered without a klippy state", evidence)
    if state == "startup":
        return _result(probe, INDETERMINATE,
                       "klippy is still starting up", evidence)
    if state != "ready":
        message = lookup(facts, "moonraker.klippy_message")
        detail = f"klippy state is {state}"
        if message is not MISSING and message:
            detail += f": {str(message).splitlines()[0]}"
        return _result(probe, UNSATISFIED, detail, evidence)
    # Klipper only reaches "ready" once every configured MCU has connected, so
    # the object list is a faithful count of live MCUs.
    objects = lookup(facts, "moonraker.mcu_objects")
    if not isinstance(objects, list):
        return _result(probe, INDETERMINATE,
                       "klippy is ready but the object list was not collected",
                       evidence)
    if len(objects) < 2:
        return _result(probe, UNSATISFIED,
                       f"klippy is ready with only {len(objects)} MCU "
                       "object(s) configured", evidence)
    return _result(probe, SATISFIED,
                   f"klippy is ready with {len(objects)} MCUs connected", evidence)


PROBES: tuple[Probe, ...] = (
    Probe("host.reachable", "transport",
          "Facts were collected from the printer", _eval_reachable),
    Probe("host.stock-client", "baseline",
          "The stock QIDI client service is still installed", _eval_stock_client),
    Probe("bootstrap.receipt", "bootstrap-host",
          "bootstrap-mainline.sh recorded a completed install",
          _eval_bootstrap_receipt),
    Probe("bootstrap.sources", "bootstrap-host",
          "Upstream Klipper, Moonraker and Katapult checkouts exist",
          _eval_bootstrap_sources),
    Probe("bootstrap.services", "bootstrap-host",
          "Klipper and Moonraker are installed as system services",
          _eval_bootstrap_services),
    Probe("bootstrap.uart-claimed", "bootstrap-host",
          "Both MCU UARTs are masked from getty and owned by dialout",
          _eval_bootstrap_uart),
    Probe("host-tuning.installed", "tune-host",
          "Persistent RK3328 host latency tuning is installed",
          _eval_host_tuning),
    Probe("config.smoke-test", "smoke-test",
          "The inert two-MCU smoke-test printer.cfg is installed",
          _eval_smoke_config),
    Probe("config.installed", "render-config",
          "A real two-MCU printer.cfg is installed", _eval_config_installed),
    Probe("mcu.online", "flash-toolhead",
          "Both printer MCUs are connected to mainline Klipper",
          _eval_mcu_online),
)

_PROBE_INDEX: dict[str, Probe] = {probe.id: probe for probe in PROBES}


def probe_ids() -> list[str]:
    return [probe.id for probe in PROBES]


def select(ids: Sequence[str] | None) -> list[Probe]:
    if not ids:
        return list(PROBES)
    unknown = [name for name in ids if name not in _PROBE_INDEX]
    if unknown:
        raise KeyError(
            f"Unknown probe(s): {', '.join(unknown)}. "
            f"Available: {', '.join(probe_ids())}"
        )
    return [_PROBE_INDEX[name] for name in ids]


def evaluate(facts: Any, context: Context | None = None,
             ids: Sequence[str] | None = None) -> list[ProbeResult]:
    """Judge every selected probe against one set of collected facts."""
    resolved = context or Context.load()
    return [probe.evaluate(facts, resolved) for probe in select(ids)]


def unreachable(reason: str, ids: Sequence[str] | None = None) -> list[ProbeResult]:
    """Every probe is indeterminate when the printer could not be reached.

    This is the expected state during the eMMC swap and while an MCU is erased,
    which is exactly when a resume decision matters most. It must therefore be
    an ordinary, well-formed answer rather than a crash.
    """
    return [
        ProbeResult(probe.id, probe.stage, INDETERMINATE, reason, {})
        for probe in select(ids)
    ]


def summarise(results: Iterable[ProbeResult]) -> dict[str, int]:
    counts = {SATISFIED: 0, UNSATISFIED: 0, INDETERMINATE: 0}
    for result in results:
        counts[result.status] = counts.get(result.status, 0) + 1
    return counts


def report(printer: str, facts: Any, results: Sequence[ProbeResult],
           reachable: bool) -> dict[str, Any]:
    return {
        "schema": SCHEMA_VERSION,
        "printer": printer,
        "reachable": reachable,
        "facts": facts if reachable else None,
        "probes": [result.as_dict() for result in results],
        "summary": summarise(results),
    }
