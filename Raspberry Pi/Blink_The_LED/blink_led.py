import time
from gpiozero import LED

# Set the GPIO pin according to your setup
led = LED(17)

def blink_led(interval_seconds, duration_seconds):
    start_time = time.time()
    end_time = start_time + duration_seconds

    while time.time() < end_time:
        led.on()
        time.sleep(interval_seconds / 2)
        led.off()
        time.sleep(interval_seconds / 2)

if __name__ == "__main__":
    # Set the interval and duration
    blink_interval = 2  # seconds
    blink_duration = 10  # seconds

    print(f"Blinking LED every {blink_interval} seconds for {blink_duration} seconds")

    blink_led(blink_interval, blink_duration)
