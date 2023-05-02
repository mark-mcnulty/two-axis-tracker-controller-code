#include "Motor.h"
#include "MotorTwo.h"
#include "pin_def.h"

void isrEndstop01();
void isrEndstop00();
void isrEncoder0();

void isrEndstop11();
void isrEndstop10();
void isrEncoder1();

volatile int counts = 0;
Motor motorEl = Motor("El");
MotorTwo motorAz = MotorTwo("Az");
int negative = -1;

void setup() {
  // attach the interrupt service routines
  attachInterrupt(ENCOD0, isrEncoder0, RISING);
  attachInterrupt(ENCOD1, isrEncoder1, RISING);

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
    // convert the input to an integer
    int numInput = userInput.toInt();
    Serial.println("moving");

    // move the motor to the inputted number of counts
    motorEl.moveRelCount(numInput);
    motorAz._counts = 0;
    motorAz.moveRelCount(numInput);
    // Serial.println(motorEl._counts);
    // Serial.println(motorAz._counts);
  // if (isInteger(userInput)) {
  // } else {
  //   // tell the user that they did not input an integer
  //   Serial.println("You did not input an integer");
  // }

  // ask the user for the input
  Serial.println("Enter a number of counts to move the motor: ");
}


/*
ELEVATION INTERRUPTS
*/
void isrEncoder0() {
    // call the isr in the motor class
    motorEl._trigger_time = millis();
    if (motorEl._trigger_time - motorEl._time_last > motorEl._wait_time) {
        motorEl.isrEncoder();
        motorEl._time_last = motorEl._trigger_time;
    }
}

void isrEndstop00() {
    // call isr in motor class
    motorEl.isrEndstop00();
}

void isrEndstop01() {
    // call the isr in the motor class
    motorEl.isrEndstop01();
}

/*
AZUMUTH INTERRUPTS
*/
void isrEncoder1() {
    // call the isr in the motor class
    motorAz._trigger_time = millis();
    if (motorAz._trigger_time - motorAz._time_last > motorAz._wait_time) {
        motorAz.isrEncoder();
        motorAz._time_last = motorAz._trigger_time;
    }
}

void isrEndstop10() {
    // call isr in motor class
    motorAz.isrEndstop00();
}

void isrEndstop11() {
    // call the isr in the motor class
    motorAz.isrEndstop01();
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