"""ESTIMATED reverse-engineered source outline.

This is not QIDI's original source and is intentionally non-runnable.
It reconstructs API shape from Cython symbols and Ghidra evidence.
Firmware: 1.7.3; subsystem: klipper; module: box_rfid.
"""

def load_config_prefix(config):
    """Estimated from `__pyx_pw_6extras_8box_rfid_1load_config_prefix`.
    Ghidra reference: decompiled.c:1223.
    Evidence identifiers: BoxRFID, config.
    """
    raise NotImplementedError('Reverse-engineered outline only')

class BoxRFID:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_1__init__`.
        Ghidra reference: decompiled.c:6461.
        Evidence identifiers: add_config_cmd, build_config, bus, config, config_fm17550_oid_d_spi_oid_d, create_oid, default_speed, fm17550_read_card, gcode, get_mcu, get_message_count, get_name, get_oid, get_printer, had_get_value, lookup_object, max_read_time, mcu, MCU_SPI_from_config, name, oid, on_restart, printer, query_fm17550_oid_d_rest_ticks_0, read_rfid_timer, register_config_callback, rfid_read_attempts, rfid_read_start_time, share_type, spi, spi_cs, split.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _build_config(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_3_build_config`.
        Ghidra reference: decompiled.c:2534.
        Evidence identifiers: cmdqueue, fm17550_read_card, get_command_queue, lookup_query_command, mcu, oid, spi.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _schedule_rfid_read(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_9_schedule_rfid_read`.
        Ghidra reference: decompiled.c:3110.
        Evidence identifiers: box_extras, color, data, eventtime, filament, gcode, get_message_count, had_get_value, max_read_time, NEVER, params, reactor, read_card_from_slot, read_rfid_timer, respond_info, rfid_read_attempts, rfid_read_start_time, s_did_not_recognize_the_filamen, save_variable, status, stepper, stepper_label, stepper_name, stop_read, temp_message_1, temp_message_2, Unrecognized_label_read_in_s, vendor.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def read_card(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_5read_card`.
        Ghidra reference: decompiled.c:990.
        Evidence identifiers: fm17550_read_card, oid, params, send.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def read_card_from_slot(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_7read_card_from_slot`.
        Ghidra reference: decompiled.c:1541.
        Evidence identifiers: params, read_card.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def start_rfid_read(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_11start_rfid_read`.
        Ghidra reference: decompiled.c:5619.
        Evidence identifiers: get_message_count, had_get_value, monotonic, NOW, reactor, read_card, read_rfid_timer, register_timer, rfid_read_attempts, rfid_read_start_time, schedule_rfid_read, stepper, stop_read, temp_message_1, temp_message_2.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def stop_read(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_8box_rfid_7BoxRFID_13stop_read`.
        Ghidra reference: decompiled.c:1859.
        Evidence identifiers: gcode, had_get_value, reactor, read_rfid_timer, respond_info, rfid_read_attempts, s_did_not_recognize_the_filamen, stepper, stepper_label, unregister_timer.
        """
        raise NotImplementedError('Reverse-engineered outline only')
