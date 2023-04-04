

#include "Motor.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder();

volatile int counts = 0;
Motor motor = Motor();

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, LOW);

  attachInterrupt(ENCOD0, isrEncoder, RISING);

  Serial.begin(9600);
}

int negative = 1;

void loop() {

  motor.moveRelCount(50 * negative);
  delay(1000);
  negative *= -1;

}

/*
NEED TO COME BACK TO THESE
*/
// interrupt service routines
void isrEncoder() {
    // update angle
    counts += 1;
    motor._counts += 1;
}

void isrEndstop00() {
    // // update angle
    // _angle_shaft = 0.0;
}

void isrEndstop01() {
    // // update angle
    // _angle_shaft = 360.0;
}