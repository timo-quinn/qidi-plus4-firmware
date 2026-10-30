"""Expose the stock Box tool-change flag to QIDI 1.8.2's status adapter.

Keep the vendor module and command handlers intact. The compatibility property
reads the saved flag that the native TOOL_CHANGE_START/END handlers maintain.
Compatible with the stock host's Python 3.7.
"""

import logging


def _saved_tool_change(tool_change):
    variables = tool_change.printer.lookup_object('save_variables').allVariables
    value = variables.get('is_tool_change', 0)
    if not isinstance(value, (bool, int)) or value not in (0, 1):
        raise ValueError('saved is_tool_change must be 0 or 1')
    return bool(value)


class BoxStatusCompat:
    def __init__(self, config):
        self._config = config
        self._printer = config.get_printer()
        self._state = 'pending'
        self._tool_change = None
        self._printer.register_event_handler('klippy:connect', self._handle_connect)

    def _handle_connect(self):
        tool_change = None
        installed = False
        try:
            box = self._printer.lookup_object('box_extras')
            tool_change = box.tool_change
            if tool_change.printer is not self._printer:
                raise ValueError('ToolChange belongs to a different printer')
            for name in ('cmd_TOOL_CHANGE_START', 'cmd_TOOL_CHANGE_END'):
                if not callable(getattr(tool_change, name, None)):
                    raise ValueError('ToolChange has no callable ' + name)
            _saved_tool_change(tool_change)
            if hasattr(tool_change, 'is_tool_change'):
                self._state = 'already-provided'
            else:
                # Do not replace an existing, uninitialised native descriptor.
                if hasattr(type(tool_change), 'is_tool_change'):
                    raise ValueError('uninitialised native is_tool_change descriptor')
                setattr(type(tool_change), 'is_tool_change', property(_saved_tool_change))
                installed = True
                if tool_change.is_tool_change != _saved_tool_change(tool_change):
                    raise ValueError('compatibility property returned the wrong state')
                self._state = 'corrected'
            self._tool_change = tool_change
        except Exception as exc:
            if installed:
                delattr(type(tool_change), 'is_tool_change')
            self._state = 'error'
            raise self._config.error('QIDI Box status compatibility: ' + str(exc))
        logging.info('QIDI Box status compatibility: %s; native commands retained', self._state)

    def get_status(self, eventtime=None):
        return {'state': self._state,
                'is_tool_change': (bool(self._tool_change.is_tool_change)
                                   if self._tool_change is not None else None)}


def load_config(config):
    return BoxStatusCompat(config)
