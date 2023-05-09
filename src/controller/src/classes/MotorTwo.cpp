#include "MotorTwo.h"
#include "Arduino.h"

MotorTwo::MotorTwo(String axis) {
    // global values
    _gear_ratio_Az = 102.28;
    _gear_ratio_El = 102.03;  
     
    // setup based on axis
    if(axis == "El"){
      _gear_ratio = _gear_ratio_El;
      pinMode(POWER0, OUTPUT);
      pinMode(DIR_REL00, OUTPUT);
      pinMode(DIR_REL01, OUTPUT);
      pinMode(ENCOD0, INPUT);
      pinMode(END00, INPUT);
      pinMode(END01, INPUT);
    } else if (axis == "Az") {
      _gear_ratio = _gear_ratio_Az;
      pinMode(POWER1, OUTPUT);
      pinMode(DIR_REL10, OUTPUT);
      pinMode(DIR_REL11, OUTPUT);
      pinMode(ENCOD1, INPUT);
      pinMode(END10, INPUT);
      pinMode(END11, INPUT);
    } else {
        Serial.println("ERROR: Axis not defined");
    }

    // fsm state 

    // constructor 
    _time_last = 0;
    _trigger_time = 0;
    _wait_time = 30;
    _counts_per_rev = 10;                    
    _gear_ratio = 1;                                
    _angle_per_count = (360.0 / _gear_ratio) / _counts_per_rev;     
    _angle_per_rev = 360.0 / _gear_ratio;           


    // motor state values
    _total_counts = 0;
    _angle_shaft = 0.0;
    _angle_tracker = 0.0;
    _dir = false;                                   // imma make CCW True and CW Flase
    _on = false;
    _moving = false;
}

void MotorTwo::turnOn() {
    digitalWrite(POWER1, HIGH);
    _on = true;
}


void MotorTwo::turnOff() {
    digitalWrite(POWER1, LOW);
    _on = false;
}


// I have to check this logic with the system
void MotorTwo::setDirection(bool dir) {
    if (dir == false) {
        digitalWrite(DIR_REL10, HIGH);
        digitalWrite(DIR_REL11, LOW);
        _dir = false;                   // check if this is CW
    }
    else if (dir == true) {
        digitalWrite(DIR_REL10, LOW);
        digitalWrite(DIR_REL11, HIGH);
        _dir = true;                    // check if this is CCW
    }
}

/*

*/
void MotorTwo::moveAbsCount(int abs_desired) {
    // figure out where we are relative to the desired count
    int desired = abs_desired - _total_counts;

    // move to the desired count
    moveRelCount(desired);
}

void MotorTwo::moveRelCount(int desired) {
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

    // turn on the motor
    turnOn();

    // wait for the motor to get to the desired count
    while(_counts <= desired){
        delay(10);
        // Serial.println("here");
    }
    
    // re-assign the total counts
    _total_counts += desired;

    // turn off the motor
    turnOff();
}

void MotorTwo::moveAbsAng(float angle) {
    // move to absolute angle
    // angle is in degrees
    // angl
}

void MotorTwo::moveRelAng(float relAngle) {
    // find the number of counts to move
    // int desired = relAngle % _angle_per_count;      // we have to take the modulus of the angle to get actual because we can only go in multiples of the angle per count
}

void MotorTwo::moveAbsAngTracker(float angle) {
    // move to absolute angle
    // angle is in degrees
    // angl
}

void MotorTwo::moveRelAngTracker(float angle) {
    // find the number of counts to move
    int desiredCount = (int) (angle / _angle_per_count);

    // move to the desired count
    moveRelCount(desiredCount);
}

/*
GETTERS
*/
float MotorTwo::getAngleShaft() {
    return _angle_shaft;
}

float MotorTwo::getAngleTracker() {
    return _angle_tracker;
}

bool MotorTwo::getDirection() {
    return _dir;
}

bool MotorTwo::getOn() {
    return _on;
}

/*
SETTERS
*/
void MotorTwo::setAngleShaft(float angle) {
    _angle_shaft = angle;
}

void MotorTwo::setAngleTracker(float angle) {
    _angle_tracker = angle;
}

void MotorTwo::setOn(bool on) {
    _on = on;
}


/*
ISRs
*/
void MotorTwo::isrEncoder(){
    // if the encoder gets triggered we need to update the count 
    // based on the direction the motor is rotating
    _counts++;
}

void MotorTwo::isrEndstop00(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();
}

void MotorTwo::isrEndstop01(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();
}


// void MotorTwo::handle_event() {
//     switch (_state) {
//         case State::WAIT:
//             if (_moving) {
//                 _state = State::GOTO;
//             }
//             break;
//         case State::GOTO:
//             if (_counts >= _counts_desired) {
//                 _moving = false;
//                 _state = State::WAIT;
//             }
//             break;
//     }
// }


