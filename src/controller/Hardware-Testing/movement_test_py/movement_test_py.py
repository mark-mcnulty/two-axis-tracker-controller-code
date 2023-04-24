# Untitled - By: Mark - Tue Mar 28 2023

import time
from machine import Pin

#
class Tracker:
    def __init__(self) -> None:
        # define the pins
        self._dir00_pin = "PG7"
        self._dir01_pin = "PC6"
        self._power0_pin = "PA0"
        self._hall_pin = "PC7"
        self._endstop00_pin = "PA8"
        self._endstop01_pin = "PC6"

        # set up the pins
        self._dir00 = Pin(self._dir00_pin, Pin.OUT)
        self._dir01 = Pin(self._dir01_pin, Pin.OUT)
        self._power = Pin(self._power0_pin, Pin.OUT)

    def power_on(self):
        self._power.value(1)

    def power_off(self):
        self._power.value(0)


idk = Tracker()

while(1):
    idk.power_on()
    print("power on")
