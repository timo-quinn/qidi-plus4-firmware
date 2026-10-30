# Documentation

Choose a topic below. For source code, tools, or local files, use the
[repository map](../README.md#repository-map).

| Topic | What you will find |
| --- | --- |
| [Firmware research](firmware/README.md) | Version comparisons, update and recovery paths, MCU analysis, hardware inventory |
| [Mainline migration](migration/README.md) | Host and MCU migration, the Box-printer runbook, post-migration Happy Hare installation |
| [Integrations](integrations/README.md) | QIDI Box and AMS compatibility, configuration regeneration, Happy Hare and stock-screen research |
| [Fixes and compatibility](fixes/README.md) | PLR repair, Box output timing and status overlays, disabling QIDILink |
| [Historical notes](history/README.md) | Dated QIDI1 migration reviews, fixes, and upstream assessments |

## Common starting points

- **Looking for v1.8.2 files?** See [firmware and backup locations](../data/README.md).
- **Comparing stock firmware?** Start with the [1.1.2 → 1.7.3 → 1.8.2 lineage](firmware/FIRMWARE-LINEAGE.md).
- **Planning a migration?** Read the [mainline guide](migration/MAINLINE-MIGRATION.md),
  then the [Box-printer runbook](migration/MIGRATION-WITH-BOX.md) if applicable.
- **Investigating a Box issue?** Start with [AMS compatibility](integrations/AMS-COMPATIBILITY.md)
  and the [fixes index](fixes/README.md).

Generated evidence is indexed under [analysis/](../analysis/README.md).
Backup and regeneration commands are indexed under [tools/](../tools/README.md).

The guides are grouped by topic; older links to `docs/NAME.md` now correspond
to the same filename inside one of the topic directories above.
