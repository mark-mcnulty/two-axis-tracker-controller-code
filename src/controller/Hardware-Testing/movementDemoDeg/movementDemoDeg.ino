#include "Motor.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder();

volatile int counts = 0;
Motor motor = Motor();

void setup() {
  // attach the interrupt service routines
  attachInterrupt(ENCOD0, isrEncoder, RISING);

  // start serial
  Serial.begin(9600);

  // ask the user for the input
  Serial.println("Enter a number of tracker degrees to move: ");
}


void loop() {
  // wait for the user to put in an input
  while(!Serial.available()) {
    // do nothing
  }

  // read the input
  String userInput = Serial.readStringUntil('\n');


  // move to the desired location
  motor.moveRelAngTracker(userInput.toFloat());
  

  // ask the user for the input
  Serial.println("Enter a number of tracker degrees to move: ");
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

// function to check it is an integer
bool isInteger(String str) {
  for (int i = 0; i < str.length(); i++) {
    if (!isdigit(str.charAt(i))) {
      return false;
    }
  }
  return true;
}