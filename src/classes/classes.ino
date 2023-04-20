#include "Motor.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder();

volatile int counts = 0;
Motor motor = Motor();
int negative = -1;
int time_last = 0;
int trigger_time = 0;
int wait_time = 35;

void setup() {
  // attach the interrupt service routines
  attachInterrupt(ENCOD0, isrEncoder, RISING);
  attachInterrupt(END00, isrEndstop00, RISING);
  attachInterrupt(END01, isrEndstop01, RISING);

  // start serial
  Serial.begin(9600);
}


void loop() {
  // move the motor
  motor.moveRelCount(10 * negative);

  // wait for the motor to move
  delay(3000);

  // change direction
  negative *= -1;
}


/*
NEED TO COME BACK TO THESE
*/
// interrupt service routines
void isrEncoder() {
    // call the isr in the motor class
    motor._trigger_time = millis();
    if (motor._trigger_time - motor._time_last > motor._wait_time) {
        motor.isrEncoder();
        motor._time_last = motor._trigger_time;
    }
}

void isrEndstop00() {
    // call isr in motor class
    motor.isrEndstop00();
}

void isrEndstop01() {
    // call the isr in the motor class
    motor.isrEndstop01();
}