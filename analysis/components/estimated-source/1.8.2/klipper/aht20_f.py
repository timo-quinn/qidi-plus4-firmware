"""ESTIMATED reverse-engineered source outline.

This is not QIDI's original source and is intentionally non-runnable.
It reconstructs API shape from Cython symbols and Ghidra evidence.
Firmware: 1.8.2; subsystem: klipper; module: aht20_f.
"""

def load_config(config):
    """Estimated from `__pyx_pw_6extras_7aht20_f_1load_config`.
    Ghidra reference: decompiled.c:10032.
    Evidence identifiers: add_sensor_factory, AHT20_F, config, get_printer, heaters, lookup_object, pheater.
    """
    raise NotImplementedError('Reverse-engineered outline only')

class AHT20_F:
    def __init__(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_1__init__`.
        Ghidra reference: decompiled.c:2788.
        Evidence identifiers: add_object, aht20_f, AHT20_F_I2C_ADDR, BOX_TEMP_READ, bus, cmd_READ_TEMP_RH, config, default_addr, default_speed, gcode, get_mcu, get_name, get_printer, get_reactor, getfloat, handle_connect, humidity, i2c, INDEX, init_sent, is_calibrated, klippy_connect, lookup_object, max_temp, mcu, MCU_I2C_from_config, min_temp, minval, name, printer, reactor, register_event_handler.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _init_aht20_f(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_19_init_aht20_f`.
        Ghidra reference: decompiled.c:9108.
        Evidence identifiers: AHT20_F_COMMANDS, aht20_f_successfully_initialized, humidity, i2c, i2c_write, info, init_sent, logging, make_measurement, monotonic, pause, reactor, RESET, temp.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _make_measurement(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_15_make_measurement`.
        Ghidra reference: decompiled.c:8609.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _reset_device(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_17_reset_device`.
        Ghidra reference: decompiled.c:13006.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def _sample_aht20_f(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_21_sample_aht20_f`.
        Ghidra reference: decompiled.c:13250.
        Evidence identifiers: AHT20_F_sensor_using_heater, AHT20_F_temperature_outside_rang, callback, estimated_print_time, eventtime, get_mcu, get_name, heater, heater_2, heater_name, heaters, humidity, i2c, info, logging, lookup_heater, lookup_object, make_measurement, max_temp, mcu, mcu_2, mcu_name, measured_time, min_temp, monotonic, not_found_for_AHT20_F_sensor, print_time, printer, reactor, report_time, set_temp, startswith.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def check_crc8(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_13check_crc8`.
        Ghidra reference: decompiled.c:4640.
        Evidence identifiers: class_getitem, crc, data, length.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def cmd_READ_TEMP_RH(self, gcmd):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_11cmd_READ_TEMP_RH`.
        Ghidra reference: decompiled.c:1838.
        Evidence identifiers: gcmd, gcode, humidity, name, respond_raw, s_temp_f_humidity_f, temp.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def get_report_time_delta(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_9get_report_time_delta`.
        Ghidra reference: decompiled.c:8855.
        Evidence identifiers: report_time.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def get_status(self, eventtime=None):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_23get_status`.
        Ghidra reference: decompiled.c:2334.
        Evidence identifiers: eventtime, humidity, temp, temperature.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def handle_connect(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_3handle_connect`.
        Ghidra reference: decompiled.c:1473.
        Evidence identifiers: init_aht20_f, NOW, reactor, sample_timer, update_timer.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def setup_callback(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_7setup_callback`.
        Ghidra reference: decompiled.c:4358.
        Evidence identifiers: callback.
        """
        raise NotImplementedError('Reverse-engineered outline only')

    def setup_minmax(self, *args, **kwargs):
        """Estimated from `__pyx_pw_6extras_7aht20_f_7AHT20_F_5setup_minmax`.
        Ghidra reference: decompiled.c:5706.
        Evidence identifiers: max_temp, min_temp.
        """
        raise NotImplementedError('Reverse-engineered outline only')
