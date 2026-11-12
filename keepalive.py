"""Keep the RT100 screen fed with time, CPU and temperature.

Unlike the library's `start-daemon`, temperatures are clamped to the 0-99
range the protocol accepts, so a hot CPU doesn't crash the loop.
"""

import argparse
import time

from epomakercontroller.configs.configs import load_main_config
from epomakercontroller.epomakercontroller import EpomakerController
from epomakercontroller.utils.sensors import get_cpu_usage, get_device_temp


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--sensor", default="coretemp-0")
    parser.add_argument("--interval", type=float, default=2.0)
    parser.add_argument("--resync-time", type=float, default=600.0)
    args = parser.parse_args()

    controller = EpomakerController(load_main_config())
    if not controller.open_device():
        raise SystemExit("RT100 not found")

    last_time_sync = 0.0
    try:
        while True:
            now = time.monotonic()
            if now - last_time_sync >= args.resync_time:
                controller.send_time()
                last_time_sync = now
            controller.send_cpu(max(0, min(100, get_cpu_usage(False))))
            controller.send_temperature(min(99, get_device_temp(args.sensor, False)))
            time.sleep(args.interval)
    except KeyboardInterrupt:
        pass
    finally:
        controller.close_device()


if __name__ == "__main__":
    main()
