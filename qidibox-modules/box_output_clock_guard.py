"""Correct the QIDI Box output scheduler to use each pin's owning MCU.

This module is a post-load compatibility overlay for QIDI's stock
``box_extras`` module.  It deliberately does not replace or wrap vendor
methods: it only corrects the ``mcu`` reference consumed by
``BoxOutput.set_pin()`` after validating both known Box outputs.
"""

import logging


_OUTPUT_NAMES = ("b_output", "e_output")
_LOG_PREFIX = "QIDI Box output clock guard"


class BoxOutputClockGuard:
    def __init__(self, config):
        self._config = config
        self._printer = config.get_printer()
        self._state = "pending"
        self._corrected_outputs = []
        self._output_status = {}
        self._applied = False
        self._printer.register_event_handler("klippy:connect", self._handle_connect)
        logging.info("%s: waiting for klippy:connect", _LOG_PREFIX)

    def _fail(self, message):
        self._state = "error"
        detail = "%s: %s" % (_LOG_PREFIX, message)
        logging.error(detail)
        return self._config.error(detail)

    @staticmethod
    def _mcu_name(mcu):
        get_name = getattr(mcu, "get_name", None)
        if not callable(get_name):
            raise TypeError("MCU object has no callable get_name()")
        name = get_name()
        if not isinstance(name, str) or not name:
            raise TypeError("MCU get_name() returned an invalid name")
        return name

    def _inspect_output(self, box_extras, output_name):
        if not hasattr(box_extras, output_name):
            raise TypeError("box_extras has no %s attribute" % (output_name,))
        output = getattr(box_extras, output_name)

        if not callable(getattr(output, "set_pin", None)):
            raise TypeError("box_extras.%s has no callable set_pin()" % output_name)
        if not hasattr(output, "mcu"):
            raise TypeError("box_extras.%s has no mcu attribute" % output_name)
        if not hasattr(output, "digital_out"):
            raise TypeError("box_extras.%s has no digital_out attribute" % output_name)

        digital_out = output.digital_out
        get_mcu = getattr(digital_out, "get_mcu", None)
        if not callable(get_mcu):
            raise TypeError("box_extras.%s.digital_out has no callable get_mcu()" % output_name)
        if not callable(getattr(digital_out, "set_digital", None)):
            raise TypeError("box_extras.%s.digital_out has no callable set_digital()" % output_name)

        source_mcu = output.mcu
        target_mcu = get_mcu()
        if source_mcu is None:
            raise TypeError("box_extras.%s.mcu is None" % output_name)
        if target_mcu is None:
            raise TypeError("box_extras.%s.digital_out.get_mcu() returned None" % output_name)
        for role, mcu in (("current", source_mcu), ("pin", target_mcu)):
            if not callable(getattr(mcu, "estimated_print_time", None)):
                raise TypeError(
                    "box_extras.%s %s MCU has no callable estimated_print_time()"
                    % (output_name, role)
                )

        source_name = self._mcu_name(source_mcu)
        target_name = self._mcu_name(target_mcu)
        return {
            "name": output_name,
            "output": output,
            "source_mcu": source_mcu,
            "target_mcu": target_mcu,
            "source_name": source_name,
            "target_name": target_name,
            "needs_correction": source_mcu is not target_mcu,
        }

    def _handle_connect(self):
        if self._applied:
            logging.info("%s: already applied; no changes made", _LOG_PREFIX)
            return

        try:
            box_extras = self._printer.lookup_object("box_extras")
        except Exception as exc:
            raise self._fail("cannot find box_extras (%s)" % (exc,))

        # Preflight both outputs before changing either.  In particular, this
        # prevents a recognized b_output from being changed when e_output is
        # absent or incompatible with the known QIDI 1.8.2 object contract.
        inspected = []
        try:
            for output_name in _OUTPUT_NAMES:
                inspected.append(self._inspect_output(box_extras, output_name))
        except Exception as exc:
            raise self._fail("incompatible vendor object: %s" % (exc,))

        changed = []
        try:
            for item in inspected:
                if item["needs_correction"]:
                    # Add the item before assignment so a custom setter that
                    # raises after changing state is included in rollback.
                    changed.append(item)
                    item["output"].mcu = item["target_mcu"]
                    if item["output"].mcu is not item["target_mcu"]:
                        raise TypeError("box_extras.%s.mcu rejected the pin MCU" % item["name"])
        except Exception as exc:
            # Attribute assignment is expected to be writable on QIDI's
            # Cython class.  Roll back earlier assignments if that expectation
            # proves false so the overlay never leaves a half-corrected pair.
            rollback_errors = []
            for item in reversed(changed):
                try:
                    item["output"].mcu = item["source_mcu"]
                except Exception as rollback_exc:
                    rollback_errors.append(str(rollback_exc))
            detail = "could not apply correction; prior changes rolled back: %s" % (exc,)
            if rollback_errors:
                detail += "; rollback errors: %s" % ", ".join(rollback_errors)
            raise self._fail(detail)

        self._corrected_outputs = [item["name"] for item in changed]
        self._output_status = {
            item["name"]: {
                "state": ("corrected" if item["needs_correction"] else "already-correct"),
                "previous_mcu": item["source_name"],
                "pin_mcu": item["target_name"],
            }
            for item in inspected
        }
        self._state = "corrected" if changed else "already-correct"
        self._applied = True

        for item in inspected:
            logging.info(
                "%s: %s %s (%s -> %s)",
                _LOG_PREFIX,
                item["name"],
                self._output_status[item["name"]]["state"],
                item["source_name"],
                item["target_name"],
            )
        logging.info(
            "%s: active; corrected=%d already-correct=%d",
            _LOG_PREFIX,
            len(changed),
            len(inspected) - len(changed),
        )

    def get_status(self, eventtime=None):
        return {
            "state": self._state,
            "corrected_count": len(self._corrected_outputs),
            "corrected_outputs": list(self._corrected_outputs),
            "outputs": dict(self._output_status),
        }


def load_config(config):
    return BoxOutputClockGuard(config)
