# add the imports
from machine import Pin

# declare variables
# double check this is the right pin
hall_pin = Pin("PJ11", Pin.IN)
counter = 0


# interrupt handler for hall sensor
def hall_interrupt(pin):
    counter += 1

# interrupt Requesst Query
hall_pin.irq(handler=hall_interrupt, trigger=Pin.IRQ_FALLING)

# main loop
while True:
    # print the value of counter should print to serial terminal
    print(counter)

