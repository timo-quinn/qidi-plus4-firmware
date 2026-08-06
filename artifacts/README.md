# Local artifacts

This directory is for reproducible build output, downloaded images, rendered
printer configurations, and temporary migration evidence. Everything except
this README is ignored by Git.

Files here are never an authoritative printer configuration. Rendered profiles
may contain device serial numbers, and live captures may contain other private
machine state. Review and sanitize them before copying anything into a tracked
repository.

`tools/migration/qidi_plus4.py` writes its default firmware and image output
here. `render-config` may also write to an explicit external workspace; it will
only replace a directory previously marked as managed by that command.
