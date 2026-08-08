#!/usr/bin/env python3
"""Switch one stock QIDI Box template between polled and vendor IRQ paths."""

import argparse
import hashlib
import json
import os
import pathlib
import re
import shutil
import stat
import sys
import tempfile


SCHEMA = "qidi-plus4-box-motion-template-guard/v1"
TRANSACTION_ID = re.compile(r"\d{8}T\d{6}Z-[0-9a-f]{16}")
SECTION = re.compile(
    r"^\s*\[\s*filament_motion_sensor\s+box_motion_sensor\s*\]\s*(?:[#;].*)?$",
    re.IGNORECASE,
)
NEXT_SECTION = re.compile(r"^\s*\[[^\]\r\n]+\]\s*(?:[#;].*)?$")
USE_IRQ = re.compile(r"^(\s*)use_irq\s*[:=]\s*([^#;\r\n]*)(.*)$", re.IGNORECASE)
DEBOUNCE = re.compile(r"^\s*debounce_us\s*[:=]", re.IGNORECASE)


def sha256(path):
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def regular_file(path, label):
    try:
        details = path.lstat()
    except OSError as exc:
        raise RuntimeError("%s is not readable: %s" % (label, exc))
    if stat.S_ISLNK(details.st_mode) or not stat.S_ISREG(details.st_mode):
        raise RuntimeError("%s must be a regular file, not a symlink" % label)
    return details


def real_directory(path, label):
    try:
        details = path.lstat()
    except OSError as exc:
        raise RuntimeError("%s is not accessible: %s" % (label, exc))
    if stat.S_ISLNK(details.st_mode) or not stat.S_ISDIR(details.st_mode):
        raise RuntimeError("%s must be a real directory, not a symlink" % label)
    if pathlib.Path(os.path.realpath(str(path))) != path:
        raise RuntimeError("%s does not resolve to its fixed path" % label)
    return details


def hardened_content(raw):
    text = raw.decode("utf-8")
    lines = text.splitlines(True)
    section_indexes = [
        index for index, line in enumerate(lines) if SECTION.match(line.rstrip("\r\n"))
    ]
    if len(section_indexes) != 1:
        raise RuntimeError(
            "template must contain exactly one [filament_motion_sensor box_motion_sensor] section"
        )
    start = section_indexes[0] + 1
    end = len(lines)
    for index in range(start, len(lines)):
        if NEXT_SECTION.match(lines[index].rstrip("\r\n")):
            end = index
            break
    use_indexes = []
    debounce_indexes = []
    for index in range(start, end):
        body = lines[index].rstrip("\r\n")
        if USE_IRQ.match(body):
            use_indexes.append(index)
        if DEBOUNCE.match(body):
            debounce_indexes.append(index)
    if len(use_indexes) != 1:
        raise RuntimeError("motion-sensor section must contain exactly one use_irq option")
    if len(debounce_indexes) > 1:
        raise RuntimeError("motion-sensor section contains duplicate debounce_us options")

    use_index = use_indexes[0]
    original = lines[use_index]
    newline = "\r\n" if original.endswith("\r\n") else "\n" if original.endswith("\n") else ""
    match = USE_IRQ.match(original.rstrip("\r\n"))
    lines[use_index] = "%suse_irq : False%s" % (match.group(1), newline)
    for index in reversed(debounce_indexes):
        del lines[index]
    return "".join(lines).encode("utf-8")


def vendor_content(raw):
    text = raw.decode("utf-8")
    lines = text.splitlines(True)
    section_indexes = [
        index for index, line in enumerate(lines) if SECTION.match(line.rstrip("\r\n"))
    ]
    if len(section_indexes) != 1:
        raise RuntimeError(
            "template must contain exactly one [filament_motion_sensor box_motion_sensor] section"
        )
    start = section_indexes[0] + 1
    end = len(lines)
    for index in range(start, len(lines)):
        if NEXT_SECTION.match(lines[index].rstrip("\r\n")):
            end = index
            break
    use_indexes = []
    debounce_indexes = []
    for index in range(start, end):
        body = lines[index].rstrip("\r\n")
        if USE_IRQ.match(body):
            use_indexes.append(index)
        if DEBOUNCE.match(body):
            debounce_indexes.append(index)
    if len(use_indexes) != 1:
        raise RuntimeError("motion-sensor section must contain exactly one use_irq option")
    if len(debounce_indexes) > 1:
        raise RuntimeError("motion-sensor section contains duplicate debounce_us options")

    use_index = use_indexes[0]
    original = lines[use_index]
    newline = "\r\n" if original.endswith("\r\n") else "\n" if original.endswith("\n") else ""
    match = USE_IRQ.match(original.rstrip("\r\n"))
    indent = match.group(1)
    lines[use_index] = "%suse_irq : True%s" % (indent, newline)
    if debounce_indexes:
        debounce_index = debounce_indexes[0]
        debounce_original = lines[debounce_index]
        debounce_newline = (
            "\r\n"
            if debounce_original.endswith("\r\n")
            else "\n" if debounce_original.endswith("\n") else ""
        )
        lines[debounce_index] = "%sdebounce_us : 50%s" % (indent, debounce_newline)
    else:
        lines.insert(use_index + 1, "%sdebounce_us : 50%s" % (indent, newline))
    return "".join(lines).encode("utf-8")


def atomic_write(target, content, details):
    descriptor, temporary_name = tempfile.mkstemp(
        prefix=".%s." % target.name,
        suffix=".tmp",
        dir=str(target.parent),
    )
    temporary = pathlib.Path(temporary_name)
    try:
        with os.fdopen(descriptor, "wb") as stream:
            stream.write(content)
            stream.flush()
            os.fsync(stream.fileno())
        os.chmod(str(temporary), stat.S_IMODE(details.st_mode))
        os.chown(str(temporary), details.st_uid, details.st_gid)
        os.replace(str(temporary), str(target))
        directory_fd = os.open(str(target.parent), os.O_RDONLY)
        try:
            os.fsync(directory_fd)
        finally:
            os.close(directory_fd)
    finally:
        try:
            temporary.unlink()
        except FileNotFoundError:
            pass


def install(box_count, transaction_id, target=None, restore_vendor=False):
    if box_count not in (1, 2, 3, 4):
        raise RuntimeError("box count must be 1 through 4")
    if not TRANSACTION_ID.fullmatch(transaction_id):
        raise RuntimeError("invalid Box motion-guard transaction identifier")
    expected_target = pathlib.Path("/home/mks/cfg_with_%d" % box_count)
    target = pathlib.Path(target) if target is not None else expected_target
    if target == expected_target and pathlib.Path(os.path.realpath(str(target))) != target:
        raise RuntimeError("Box template does not resolve to its fixed path")
    details = regular_file(target, "QIDI Box template")
    real_directory(target.parent, "QIDI Box template directory")
    before_digest = sha256(target)
    current = target.read_bytes()
    transform = vendor_content if restore_vendor else hardened_content
    desired = transform(current)
    changed = desired != current
    backup = None

    if changed:
        backup_root = target.parent / ".qidi-plus4-backups"
        if os.path.lexists(str(backup_root)):
            real_directory(backup_root, "backup directory")
        else:
            backup_root.mkdir(mode=0o700)
            os.chown(str(backup_root), details.st_uid, details.st_gid)
        prefix = "box-motion-vendor-" if restore_vendor else "box-motion-guard-"
        backup_dir = backup_root / (prefix + transaction_id)
        backup_dir.mkdir(mode=0o700)
        os.chown(str(backup_dir), details.st_uid, details.st_gid)
        backup_path = backup_dir / target.name
        shutil.copy2(str(target), str(backup_path), follow_symlinks=False)
        os.chown(str(backup_path), details.st_uid, details.st_gid)
        backup = {
            "path": str(backup_path),
            "sha256": sha256(backup_path),
        }
        if backup["sha256"] != before_digest:
            raise RuntimeError("Box template backup SHA-256 mismatch")
        current_details = regular_file(target, "QIDI Box template")
        if (
            sha256(target) != before_digest
            or current_details.st_ino != details.st_ino
            or current_details.st_dev != details.st_dev
        ):
            raise RuntimeError("QIDI Box template changed during installation")
        atomic_write(target, desired, details)

    after = regular_file(target, "hardened QIDI Box template")
    after_digest = sha256(target)
    verified = transform(target.read_bytes()) == target.read_bytes()
    if not verified:
        raise RuntimeError("post-install QIDI Box template verification failed")
    return {
        "schema": SCHEMA,
        "ok": True,
        "changed": changed,
        "verified": True,
        "box_count": box_count,
        "transaction_id": transaction_id,
        "target": {
            "path": str(target),
            "before_sha256": before_digest,
            "after_sha256": after_digest,
            "mode": "%04o" % stat.S_IMODE(after.st_mode),
            "uid": after.st_uid,
            "gid": after.st_gid,
        },
        "backup": backup,
        "use_irq": bool(restore_vendor),
        "debounce_us_present": bool(restore_vendor),
        "active_config_changed": False,
        "klipper_service_action": "none",
        "klipper_restarted": False,
        "activation_required": True,
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--box-count", required=True, type=int, choices=(1, 2, 3, 4))
    parser.add_argument("--transaction-id", required=True)
    parser.add_argument("--restore-vendor", action="store_true")
    args = parser.parse_args()
    try:
        result = install(
            args.box_count,
            args.transaction_id,
            restore_vendor=args.restore_vendor,
        )
    except Exception as exc:
        result = {
            "schema": SCHEMA,
            "ok": False,
            "box_count": args.box_count,
            "transaction_id": args.transaction_id,
            "target": {"path": "/home/mks/cfg_with_%d" % args.box_count},
            "active_config_changed": False,
            "klipper_service_action": "none",
            "klipper_restarted": False,
            "activation_required": True,
            "error": str(exc),
        }
        print(json.dumps(result, sort_keys=True))
        return 1
    print(json.dumps(result, sort_keys=True))
    return 0


if __name__ == "__main__":
    sys.exit(main())
