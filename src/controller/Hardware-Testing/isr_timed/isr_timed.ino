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
  attachInterrupt(ENCOD0, isrEncoder, RISING);
  Serial.begin(9600);
}


void loop() {
  motor.moveRelCount(10 * negative);
  delay(3000);
  negative *= -1;
  Serial.print(motor._counts);
}


/*
NEED TO COME BACK TO THESE
*/
// interrupt service routines
void isrEncoder() {
    // call the isr in the motor class
    trigger_time = millis();
    if (trigger_time - time_last > wait_time) {
        motor.isrEncoder();
        time_last = trigger_time;
    }
}

void isrEndstop00() {
    // // update angle
    // _angle_shaft = 0.0;
}

void isrEndstop01() {
    // // update angle
    // _angle_shaft = 360.0;
}