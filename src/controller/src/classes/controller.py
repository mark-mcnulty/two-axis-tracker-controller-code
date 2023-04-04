import time
import machine

class Controller:
    def __init__(self) -> None:
        # define the pins
        self._dir1_pin = 0
        self._dir2_pin = 1
        self._power_pin = 2
        self._hall_pin = 3
        self._endstop_min_pin = 4
        self._endstop_max_pin = 5

        # set up the pins
        self._dir1 = machine.Pin(self._dir1_pin, machine.Pin.OUT)
        self._dir2 = machine.Pin(self._dir2_pin, machine.Pin.OUT)
        self._power = machine.Pin(self._power_pin, machine.Pin.OUT)
        self._hall = machine.Pin(self._hall_pin, machine.Pin.IN)
        self._endstop_min = machine.Pin(self._endstop_min_pin, machine.Pin.IN)
        self._endstop_max = machine.Pin(self._endstop_max_pin, machine.Pin.IN)

        # define variables
        self._power_state = False       # False = off, True = on
        self._direction = False         # False = CCW, True = CW


        # make the hall sensor interrupt
        self._hall.irq(trigger=machine.Pin.IRQ_RISING, handler=self._hall_handler)
        self._endstop_min.irq(trigger=machine.Pin.IRQ_RISING, handler=self._endstop_handler_min)
        self._endstop_max.irq(trigger=machine.Pin.IRQ_RISING, handler=self._endstop_handler_max)
        pass

    def set_direction(self, direction: bool):
        self._direction = direction
        self._dir1.value(self._direction)
        self._dir2.value(not self._direction)
        pass

    def set_power(self, power: bool):
        self._power_state = power
        self._power.value(self._power_state)
        pass

    def _hall_handler(self):
        print("Hall sensor triggered")
        pass

    def _endstop_handler_min(self):
        print("Endstop min triggered")
        pass

    def _endstop_handler_max(self):
        print("Endstop max triggered")
        pass

