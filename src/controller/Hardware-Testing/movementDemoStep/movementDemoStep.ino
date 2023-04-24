#include "Motor.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder();

volatile int counts = 0;
Motor motor = Motor();
int negative = -1;

void setup() {
  // attach the interrupt service routines
  attachInterrupt(ENCOD0, isrEncoder, RISING);

  // start serial
  Serial.begin(9600);

  // ask the user for the input
  Serial.println("Enter a number of counts to move the motor: ");
}


void loop() {
  // wait for the user to put in an input
  while(!Serial.available()) {
    // do nothing
  }

  // read the input
  String userInput = Serial.readStringUntil('\n');


  // check if the user did indeed input a integer
  if (isInteger(userInput)) {
    // convert the input to an integer
    int numInput = userInput.toInt();

    // move the motor to the inputted number of counts
    motor.moveRelCount(numInput);
  } else {
    // tell the user that they did not input an integer
    Serial.println("You did not input an integer");
  }

  // ask the user for the input
  Serial.println("Enter a number of counts to move the motor: ");
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