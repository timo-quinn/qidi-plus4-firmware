"""ESTIMATED reverse-engineered source outline.

This is not QIDI's original source and is intentionally non-runnable.
It reconstructs API shape from Cython symbols and Ghidra evidence.
Firmware: 1.7.3; subsystem: klipper; module: buttons_irq.
"""

def load_config(config):
    """Estimated from `__pyx_pw_6extras_11buttons_irq_1load_config`.
    Ghidra reference: decompiled.c:1339.
    Evidence identifiers: config, MCU_irq_button.
    """
    raise NotImplementedError('Reverse-engineered outline only')

class _IRQButtonMCU:
    def _build_config(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_5_build_config`.
        Ghidra reference: decompiled.c:1916.
        Evidence identifiers: ack_cmd, add_config_cmd, alloc_command_queue, cmd_queue, config_irq_button_oid_d_pin_s_pu, debounce_us, get, info, irq_button_debounce_us_d, logging, lookup_command, mcu, oid, pin, pin_list.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def setup_buttons(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_11buttons_irq_13_IRQButtonMCU_3setup_buttons`.
        Ghidra reference: decompiled.c:2925.
        Evidence identifiers: append, callback, callbacks, get, invert, mask, pin_list, pin_params, pin_params_list, shift.
        """
        raise NotImplementedError('Reverse-engineered outline only')

class MCU_irq_button:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_11buttons_irq_14MCU_irq_button_1__init__`.
        Ghidra reference: decompiled.c:1506.
        Evidence identifiers: config, get_printer, irq_buttons, printer.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def register_buttons(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_11buttons_irq_14MCU_irq_button_3register_buttons`.
        Ghidra reference: decompiled.c:6640.
        Evidence identifiers: callback, can_invert, can_pullup, chip, chip_name, Creating_new_IRQ_button_object_f, debounce_us, error, get, IRQ_button_pins_must_be_on_same, irq_buttons, IRQButtonMCU, logging, lookup_object, lookup_pin, mcu, mcu_button, mcu_name, pin, pin_list, pin_params, pin_params_list, pins, ppins, printer, setup_buttons, warning.
        """
        raise NotImplementedError('Reverse-engineered outline only')
