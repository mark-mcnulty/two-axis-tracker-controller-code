#include "Motor.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder();

volatile int counts = 0;
Motor motor = Motor();
int negative = -1;

void setup() {
  Serial.begin(9600);
}


void loop() {
  motor.moveRelCount(10 * negative);
  delay(6000);
  negative *= -1;
  Serial.print(motor._counts);
}


/*
NEED TO COME BACK TO THESE
*/
// interrupt service routines
void isrEncoder() {
    // call the isr in the motor class
    motor.isrEncoder();
}

void isrEndstop00() {
    // // update angle
    // _angle_shaft = 0.0;
}

void isrEndstop01() {
    // // update angle
    // _angle_shaft = 360.0;
}