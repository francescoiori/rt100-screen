#!/bin/sh
# Set up the RT100 screen on an Ubuntu desktop login.
# Installs the packages, the keyboard permission, the background service,
# and the RT100 app. Does not flash the screen. See ./flash.sh for that.
set -eu

ROOT=$(CDPATH= cd -- "$(dirname "$0")" && pwd)
PYTHON=${PYTHON:-python3}

if [ -z "${XDG_RUNTIME_DIR:-}" ] || ! systemctl --user status >/dev/null 2>&1; then
  echo "Run this from your Ubuntu desktop login. The background service is per user." >&2
  exit 1
fi

if command -v apt-get >/dev/null 2>&1; then
  echo "Installing Ubuntu packages (this asks for your password)..."
  sudo apt-get install -y \
    python3 python3-venv python3-pip python3-gi \
    gir1.2-gtk-3.0 gir1.2-ayatanaappindicator3-0.1 \
    x11-utils curl
  echo "Allowing your user to open the keyboard..."
  sudo cp "$ROOT/screen/99-epomaker-rt100.rules" /etc/udev/rules.d/99-epomaker-rt100.rules
  sudo udevadm control --reload-rules
  echo "Unplug the keyboard and plug it back in once this script finishes."
else
  echo "This installer uses apt. Install Python 3.10+, python3-gi, GTK, AyatanaAppIndicator, x11-utils, and curl yourself." >&2
fi

if ! "$PYTHON" -c 'import sys; raise SystemExit(0 if sys.version_info >= (3, 10) else 1)'; then
  echo "Python 3.10 or newer is required." >&2
  exit 1
fi

"$PYTHON" -m venv "$ROOT/.venv"
"$ROOT/.venv/bin/pip" install -r "$ROOT/requirements.txt"

install_unit() {
  src=$1
  dest=$2
  sed "s|@ROOT@|$ROOT|g" "$src" > "$dest"
}

mkdir -p "$HOME/.config/systemd/user" "$HOME/.local/share/applications"
install_unit "$ROOT/screen/rt100screen.service" "$HOME/.config/systemd/user/rt100screen.service"
install_unit "$ROOT/screen/rt100-indicator.service" "$HOME/.config/systemd/user/rt100-indicator.service"
sed "s|@ROOT@|$ROOT|g" "$ROOT/screen/rt100-screen.desktop" > "$HOME/.local/share/applications/rt100-screen.desktop"
chmod +x "$ROOT/screen/rt100-panel" "$ROOT/screen/rt100-indicator" "$ROOT/flash.sh"

systemctl --user daemon-reload
systemctl --user enable --now rt100screen.service

if "$PYTHON" -c 'import gi; gi.require_version("Gtk", "3.0"); gi.require_version("AyatanaAppIndicator3", "0.1"); from gi.repository import Gtk, AyatanaAppIndicator3' >/dev/null 2>&1; then
  systemctl --user enable --now rt100-indicator.service
else
  echo "Top-bar icon was not started. The RT100 app and the background service are still installed."
fi

echo
echo "Background service: rt100screen.service (starts now, and again each time you log in)."
echo "App menu: RT100. It opens http://127.0.0.1:8765"
echo "The screen keeps its original clock until you flash:"
echo "  $ROOT/flash.sh"
