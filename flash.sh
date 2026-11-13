#!/bin/sh
# Write the custom screen firmware. A bad write can brick the screen for good.
set -eu

ROOT=$(CDPATH= cd -- "$(dirname "$0")" && pwd)
IMAGE=$ROOT/device/custom/out/firmwareOledFile.bin
PY=$ROOT/.venv/bin/python

cat << 'EOF'
This writes new firmware to the screen on your RT100 keyboard.

You do this at your own risk. If the write fails, or the cable comes out
during it, the screen can stay blank forever, and the keyboard can stop
talking to the computer. There is no recovery mode, no second copy, and no
debug port. This software comes with no warranty. If you are not willing to
lose this keyboard, stop here.

Use the cable plugged into the keyboard. Do not use the wireless dongle.
Leave the cable in until this script says the firmware was verified.

EOF

if [ "${1:-}" != "--yes" ]; then
  printf 'Type YES to flash, or anything else to stop: '
  read -r answer
  if [ "$answer" != "YES" ]; then
    echo "Stopped. Nothing was written."
    exit 1
  fi
fi

if [ ! -x "$PY" ]; then
  echo "Run ./install.sh first." >&2
  exit 1
fi
if [ ! -f "$IMAGE" ]; then
  echo "Firmware image not found: $IMAGE" >&2
  exit 1
fi

echo "Checking the image, without touching the keyboard..."
( cd "$ROOT/screen" && "$PY" oled_flash.py --dry-run "$IMAGE" )

echo "Stopping the screen program so nothing else is using the keyboard..."
systemctl --user stop rt100screen.service 2>/dev/null || true
sleep 0.5
if pgrep -f '[r]t100screen.py' >/dev/null; then
  echo "The screen program is still running. Unplug and replug the keyboard, then try again." >&2
  echo "Nothing was written." >&2
  exit 1
fi

set +e
( cd "$ROOT/screen" && "$PY" oled_flash.py "$IMAGE" )
status=$?
set -e

if [ "$status" -ne 0 ]; then
  echo
  echo "The flash did not finish cleanly."
  echo "Leave the cable plugged in. If the keyboard stops responding, unplug it and plug it back in."
  echo "Do not start a second flash unless the message above said nothing was written."
  exit "$status"
fi

systemctl --user start rt100screen.service 2>/dev/null || true
echo
echo "Firmware verified. Open http://127.0.0.1:8765 or the RT100 app."
