from __future__ import annotations

import importlib.util
import pathlib
import shutil
import subprocess

import pytest


REPO_ROOT = pathlib.Path(__file__).resolve().parents[1]
MODULE_PATH = REPO_ROOT / "tools" / "Analyze-QidiFirmwareLineage.py"
SPEC = importlib.util.spec_from_file_location("qidi_firmware_lineage", MODULE_PATH)
assert SPEC and SPEC.loader
lineage = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(lineage)

PUBLISHED_PATCHES = sorted((REPO_ROOT / "analysis").rglob("*.patch"))


@pytest.mark.parametrize(
    "path",
    PUBLISHED_PATCHES,
    ids=lambda path: path.relative_to(REPO_ROOT).as_posix(),
)
def test_published_patch_is_nul_free_utf8(path: pathlib.Path) -> None:
    data = path.read_bytes()

    assert b"\x00" not in data
    data.decode("utf-8")


@pytest.mark.skipif(shutil.which("git") is None, reason="git is required")
def test_repo_patch_generation_skips_nul_bearing_source(tmp_path: pathlib.Path) -> None:
    snapshot = tmp_path / "snapshot"
    repo = snapshot / "home" / "mks" / "klipper"
    repo.mkdir(parents=True)
    subprocess.run(["git", "init", "--quiet"], cwd=repo, check=True)
    (repo / ".gitattributes").write_text("*.h text\n", encoding="utf-8")
    (repo / "safe.py").write_text("value = 1\n", encoding="utf-8")
    (repo / "binary-looking.h").write_bytes(b"header\n\x00old\n")
    (repo / "non-utf8.h").write_bytes(b"header\n\xffold\n")
    subprocess.run(["git", "add", "."], cwd=repo, check=True)
    subprocess.run(
        ["git", "-c", "user.name=Test", "-c", "user.email=test@example.invalid",
         "commit", "--quiet", "-m", "fixture"],
        cwd=repo,
        check=True,
    )
    (repo / "safe.py").write_text("value = 2\n", encoding="utf-8")
    (repo / "binary-looking.h").write_bytes(b"header\n\x00new\n")
    (repo / "non-utf8.h").write_bytes(b"header\n\xffnew\n")
    (repo / "untracked-invalid.txt").write_bytes(b"\xff\n")
    output = tmp_path / "output"
    output.mkdir()

    lineage.write_repo_patches([("test", snapshot)], output)

    patch = output / "patches" / "vtest-klipper-vs-recorded-head.patch"
    semantic = output / "patches" / "vtest-klipper-vs-recorded-head.semantic.patch"
    skipped = output / "patches" / "vtest-klipper-vs-recorded-head.skipped.txt"
    for published in (patch, semantic):
        data = published.read_bytes()
        assert b"\x00" not in data
        assert "safe.py" in data.decode("utf-8")
        assert "binary-looking.h" not in data.decode("utf-8")
        assert "non-utf8.h" not in data.decode("utf-8")
    skipped_text = skipped.read_text(encoding="utf-8")
    assert "binary-looking.h" in skipped_text
    assert "contains-nul" in skipped_text
    assert "non-utf8.h" in skipped_text
    assert "not-utf8" in skipped_text

    untracked_patch = output / "patches" / "vtest-klipper-untracked-readable.patch"
    untracked_skipped = (
        output / "patches" / "vtest-klipper-untracked-readable.skipped.txt"
    )
    assert "untracked-invalid.txt" not in untracked_patch.read_text(encoding="utf-8")
    assert "untracked-invalid.txt" in untracked_skipped.read_text(encoding="utf-8")
