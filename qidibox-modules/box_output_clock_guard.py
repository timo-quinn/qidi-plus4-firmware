"""Apply post-load guards to QIDI's dynamically registered Box objects.

This module is a post-load compatibility overlay for QIDI's stock
``box_extras`` module. It corrects the ``mcu`` reference consumed by
``BoxOutput.set_pin()`` and wraps the dynamically registered ``RELOAD_ALL``
command only after the vendor module has created it. Automatic ``RFID=1``
insertion is quarantined by default; explicit calls still reach QIDI's
original callback.
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
        self._box_extras = None
        self._original_reload_all = None
        self._reload_all_guarded = False
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

    def _install_reload_all_guard(self, box_extras):
        get_value = getattr(box_extras, "get_value_by_key", None)
        if not callable(get_value):
            raise TypeError("box_extras has no callable get_value_by_key()")
        gcode = self._printer.lookup_object("gcode")
        register = getattr(gcode, "register_command", None)
        if not callable(register):
            raise TypeError("gcode has no callable register_command()")

        original = register("RELOAD_ALL", None)
        if not callable(original):
            raise TypeError("QIDI RELOAD_ALL command is not registered")
        try:
            register(
                "RELOAD_ALL",
                self._cmd_reload_all,
                desc="Guard automatic QIDI Box insertion",
            )
        except Exception:
            register("RELOAD_ALL", original)
            raise
        self._box_extras = box_extras
        self._original_reload_all = original
        self._reload_all_guarded = True

    def _cmd_reload_all(self, gcmd):
        automatic = gcmd.get_int("RFID", 0) == 1
        enabled = int(self._box_extras.get_value_by_key("qidi_box_auto_insert", 0)) == 1
        if automatic and not enabled:
            gcmd.respond_info(
                "QIDI Box automatic insertion is disabled after a Box MCU watchdog reset. "
                "Use LOAD_Tn or enable it explicitly."
            )
            return
        self._original_reload_all(gcmd)

    def _handle_connect(self):
        if self._applied:
            logging.info("%s: already applied; no changes made", _LOG_PREFIX)
            return

        try:
            box_extras = self._printer.lookup_object("box_extras")
        except Exception as exc:
            # Stock QIDI's box_detect may regenerate box.cfg and request a
            # second Klipper start. During that transitional first start the
            # Box include can legitimately be absent. Halting Klipper here
            # prevents box_detect from completing its own recovery cycle.
            self._state = "inactive-no-box"
            logging.warning(
                "%s: box_extras is not loaded; deferring until the next Klipper start (%s)",
                _LOG_PREFIX,
                exc,
            )
            return

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
            self._install_reload_all_guard(box_extras)
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
            "%s: active; corrected=%d already-correct=%d reload-all-guarded=%s",
            _LOG_PREFIX,
            len(changed),
            len(inspected) - len(changed),
            self._reload_all_guarded,
        )

    def get_status(self, eventtime=None):
        return {
            "state": self._state,
            "corrected_count": len(self._corrected_outputs),
            "corrected_outputs": list(self._corrected_outputs),
            "outputs": dict(self._output_status),
            "reload_all_guarded": self._reload_all_guarded,
        }


def load_config(config):
    return BoxOutputClockGuard(config)
