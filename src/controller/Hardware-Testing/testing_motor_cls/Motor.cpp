#include "Motor.h"
#include "Arduino.h"

Motor::Motor() {
    // constructor 
    _counts_per_rev = 10;                           // probably should check this is bc im using rising i think change will be inconsistant check if you want
    _gear_ratio = 1;                                // so wrong rn
    _angle_per_count = 360.0 / _counts_per_rev;     // so wrong rn
    _angle_per_rev = 360.0 * _gear_ratio;           // so wrong rn


    // motor state values
    _angle_shaft = 0.0;
    _angle_tracker = 0.0;
    _dir = false;                                   // imma make CCW True and CW Flase
    _on = false;
    _moving = false;


    // set up pins
    pinMode(POWER0, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(DIR_REL01, OUTPUT);
    pinMode(ENCOD0, INPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);

    // set up interrupts

}

void Motor::turnOn() {
    digitalWrite(POWER0, HIGH);
    _on = true;
}


void Motor::turnOff() {
    digitalWrite(POWER0, LOW);
    _on = false;
}


// I have to check this logic with the system
void Motor::setDirection(bool dir) {
    if (dir == false) {
        digitalWrite(DIR_REL00, HIGH);
        digitalWrite(DIR_REL01, LOW);
        _dir = false;                   // check if this is CW
    }
    else if (dir == true) {
        digitalWrite(DIR_REL00, LOW);
        digitalWrite(DIR_REL01, HIGH);
        _dir = true;                    // check if this is CCW
    }
}

void Motor::moveAbsCount(int count) {
    // move to absolute count
    // count is in encoder counts    

}

void Motor::moveRelCount(int desired) {
    _counts = 0;
    _moving = true;
    _counts_desired = desired;

    
    // check that dir is set right
    if (desired > 0) {
      setDirection(true);
    } else {
      setDirection(false);
      desired *= -1;
    }

    turnOn();
    while(_counts < desired){
      Serial.println(_counts);
    }
    turnOff();
}

void Motor::moveAbsAng(float angle) {
    // move to absolute angle
    // angle is in degrees
    // angl
}

void Motor::moveRelAng(float angle) {
    // move to relative angle
    // angle is in degrees
}

/*
GETTERS
*/
float Motor::getAngleShaft() {
    return _angle_shaft;
}

float Motor::getAngleTracker() {
    return _angle_tracker;
}

bool Motor::getDirection() {
    return _dir;
}

bool Motor::getOn() {
    return _on;
}

/*
SETTERS
*/
void Motor::setAngleShaft(float angle) {
    _angle_shaft = angle;
}

void Motor::setAngleTracker(float angle) {
    _angle_tracker = angle;
}

void Motor::setOn(bool on) {
    _on = on;
}


/*
ISRs
*/
void Motor::isrEncoder(){

}

void Motor::isrEndstop00(){

}

void Motor::isrEndstop01(){
    
}



