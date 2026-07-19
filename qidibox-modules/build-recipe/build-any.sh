#!/bin/bash
set -euo pipefail
PY="${1:-python}"
echo "== building with $($PY --version 2>&1) =="
$PY /work/build-recipe/apply-compatibility-patches.py /work/src
$PY -m pip install --no-cache-dir "cython==3.0.12" >/tmp/pip.log 2>&1 || { tail -20 /tmp/pip.log; exit 1; }
INC=$($PY -c "import sysconfig; print(sysconfig.get_path('include'))")
echo "include: $INC ; glibc: $(ldd --version 2>/dev/null | head -1)"
mkdir -p /work/out && cd /work/src
for m in aht20_f box_detect box_extras box_rfid box_stepper; do
  $PY -m cython -3 "$m.py" -o "$m.c"
  gcc -shared -fPIC -O2 -I"$INC" "$m.c" -o "/work/out/$m.so"
  echo "built $m.so ($(stat -c %s /work/out/$m.so) bytes)"
done
$PY -m pip install -q pyudev >/dev/null 2>&1 || true
cd /work/out
$PY /work/build-recipe/verify-box-extras.py /work/out
for f in *.so; do echo "$f: $(readelf -h "$f" 2>/dev/null | awk -F: '/Machine/{print $2}' | xargs) $(strings "$f" | grep -oE '_cython_[0-9_]+' | head -1)"; done
