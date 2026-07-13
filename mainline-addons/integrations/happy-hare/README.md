# Happy Hare hooks

Install and commission Happy Hare using
[`../../docs/HAPPY-HARE-INSTALLATION.md`](../../../docs/HAPPY-HARE-INSTALLATION.md)
before adding Plus4-specific hooks.

`plus4-hooks.cfg.example` is deliberately inert. It names the future cutter
and purge attachment points without claiming that a stock QIDI Box works on
mainline Klipper. Replace the refusal only after the independent
`PLUS4_CUTTER` and purge-park sequences have been hardware-tested.

Keep Happy Hare as the only material state machine. These hooks must not load
QIDI's `multi_color_controller`, `box_extras`, or `box_stepper` modules.

