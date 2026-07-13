from qidi_screen_bridge.interfaces import BridgePolicy, PrinterSnapshot


def test_policy_fails_closed():
    policy = BridgePolicy()
    assert not policy.screen_writes_enabled
    assert not policy.permits_action("pause")


def test_policy_requires_global_and_per_action_enablement():
    allow_list_only = BridgePolicy(allowed_actions=frozenset({"pause"}))
    enabled = BridgePolicy(
        printer_actions_enabled=True,
        allowed_actions=frozenset({"pause"}),
    )
    assert not allow_list_only.permits_action("pause")
    assert enabled.permits_action("pause")
    assert not enabled.permits_action("run_gcode")


def test_snapshot_is_backend_neutral():
    snapshot = PrinterSnapshot(state="printing", progress=0.25, position=(1.0, 2.0, 3.0))
    assert snapshot.progress == 0.25
