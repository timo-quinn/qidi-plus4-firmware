import importlib.util
import unittest
from pathlib import Path
from types import SimpleNamespace

path = Path(__file__).resolve().parents[1] / 'box_status_compat.py'
spec = importlib.util.spec_from_file_location('box_status_compat', path)
compat = importlib.util.module_from_spec(spec)
spec.loader.exec_module(compat)


def runtime():
    class ToolChange:
        def cmd_TOOL_CHANGE_START(self):
            variables.allVariables['is_tool_change'] = 1

        def cmd_TOOL_CHANGE_END(self):
            variables.allVariables['is_tool_change'] = 0

    variables = SimpleNamespace(allVariables={})
    tool = ToolChange()
    box = SimpleNamespace(tool_change=tool)
    objects = {'box_extras': box, 'save_variables': variables}
    missing = object()

    def lookup_object(name, default=missing):
        if name in objects:
            return objects[name]
        if default is missing:
            raise ValueError(f"Unknown config object '{name}'")
        return default

    printer = SimpleNamespace(lookup_object=lookup_object,
                              objects=objects,
                              register_event_handler=lambda *args: None)
    tool.printer = printer
    config = SimpleNamespace(get_printer=lambda: printer, error=ValueError)
    return compat.load_config(config), tool, variables


def check_property_tracks_current_saved_state_without_replacing_commands(runtime):
    overlay, tool, variables = runtime
    start = type(tool).cmd_TOOL_CHANGE_START
    end = type(tool).cmd_TOOL_CHANGE_END
    overlay._handle_connect()
    assert tool.is_tool_change is False
    tool.cmd_TOOL_CHANGE_START()
    assert tool.is_tool_change is True
    tool.cmd_TOOL_CHANGE_END()
    assert tool.is_tool_change is False
    variables.allVariables['is_tool_change'] = 1
    assert tool.is_tool_change is True
    assert type(tool).cmd_TOOL_CHANGE_START is start
    assert type(tool).cmd_TOOL_CHANGE_END is end
    assert overlay.get_status() == {'state': 'corrected', 'is_tool_change': True}


def check_existing_native_attribute_is_preserved(runtime):
    overlay, tool, variables = runtime
    tool.is_tool_change = True
    overlay._handle_connect()
    assert tool.is_tool_change is True
    assert not hasattr(type(tool), 'is_tool_change')
    assert variables.allVariables == {}
    assert overlay.get_status()['state'] == 'already-provided'


def check_invalid_saved_flag_does_not_modify_the_class(runtime):
    overlay, tool, variables = runtime
    variables.allVariables['is_tool_change'] = 'invalid'
    with unittest.TestCase().assertRaisesRegex(ValueError, 'must be 0 or 1'):
        overlay._handle_connect()
    assert not hasattr(type(tool), 'is_tool_change')


def check_repeated_connect_does_not_replace_the_property(runtime):
    overlay, tool, variables = runtime
    overlay._handle_connect()
    descriptor = type(tool).is_tool_change
    overlay._handle_connect()
    assert type(tool).is_tool_change is descriptor
    variables.allVariables['is_tool_change'] = 1
    assert tool.is_tool_change is True


def check_uninitialised_native_descriptor_is_not_overwritten(runtime):
    overlay, tool, _ = runtime
    def unavailable(self):
        raise AttributeError('not initialised')
    descriptor = property(unavailable)
    type(tool).is_tool_change = descriptor
    with unittest.TestCase().assertRaisesRegex(ValueError, 'uninitialised native'):
        overlay._handle_connect()
    assert type(tool).is_tool_change is descriptor


class BoxStatusCompatTests(unittest.TestCase):
    def test_absent_box_does_not_halt_connect_and_can_recover(self):
        overlay, tool, variables = runtime()
        objects = tool.printer.objects
        box = objects.pop('box_extras')
        # box_detect can omit the Box config during its detection/restart cycle.
        overlay._handle_connect()
        self.assertEqual(overlay.get_status(),
                         {'state': 'inactive-no-box', 'is_tool_change': None})
        self.assertFalse(hasattr(type(tool), 'is_tool_change'))
        self.assertEqual(variables.allVariables, {})
        objects['box_extras'] = box
        overlay._handle_connect()
        self.assertEqual(overlay.get_status()['state'], 'corrected')
        tool.cmd_TOOL_CHANGE_START()
        self.assertTrue(tool.is_tool_change)

    def test_property_tracks_saved_state(self):
        check_property_tracks_current_saved_state_without_replacing_commands(runtime())

    def test_preserves_native_attribute(self):
        check_existing_native_attribute_is_preserved(runtime())

    def test_rejects_invalid_flag(self):
        check_invalid_saved_flag_does_not_modify_the_class(runtime())

    def test_repeated_connect(self):
        check_repeated_connect_does_not_replace_the_property(runtime())

    def test_preserves_uninitialised_descriptor(self):
        check_uninitialised_native_descriptor_is_not_overwritten(runtime())


if __name__ == '__main__':
    unittest.main()
