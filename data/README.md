# Local data

`printer-backups/` contains the raw and extracted printer backups used as input
to the analysis tools. That directory is ignored by Git because backups may
contain credentials, API keys, databases, SSH material, and other private
printer state.

The expected analysis input layout is:

```text
data/printer-backups/analysis/
|-- qidi1/  # firmware 1.8.2 with QIDI Box
`-- qidi2/  # firmware 1.7.3
```

Do not force-add the backup directory to Git. Publish only reviewed outputs from
`docs/`, `analysis/`, and `tools/`.
