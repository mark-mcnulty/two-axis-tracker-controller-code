#include "Motor.h"
#include "Arduino.h"

Motor::Motor() {
    // fsm state 
    _state = State::WAIT;
    // constructor 
    _counts_per_rev = 10;                           
    _gear_ratio = 1;                                
    _angle_per_count = 360.0 / _counts_per_rev;     
    _angle_per_rev = 360.0 * _gear_ratio;           


    // motor state values
    _angle_shaft = 0.0;
    _angle_tracker = 0.0;
    _dir = false;                                   // imma make CCW True and CW Flase
    _on = false;
    _moving = false;


    // set up pins for one axis
    pinMode(POWER0, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(DIR_REL01, OUTPUT);
    pinMode(ENCOD0, INPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);
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
    while(_counts <= desired){
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
    // if the encoder gets triggered we need to update the count 
    // based on the direction the motor is rotating
    // if (_dir == true) {
    //     _counts++;
    // } else {
    //     _counts--;
    // }
    _counts++;
}

void Motor::isrEndstop00(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();

    // we then want to set the current position
    // which will be the min position of the axis
}

void Motor::isrEndstop01(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();

    // we then want to set the current position
    // which will be the max position of the axis
}


void Motor::handle_event() {
    switch (_state) {
        case State::WAIT:
            if (_moving) {
                _state = State::GOTO;
            }
            break;
        case State::GOTO:
            if (_counts >= _counts_desired) {
                _moving = false;
                _state = State::WAIT;
            }
            break;
    }
}


