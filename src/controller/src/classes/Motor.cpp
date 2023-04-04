#include Motor.h

Motor::Motor() {
    // constructor 
    _counts_per_rev = 10;                           // probably should check this is bc im using rising i think change will be inconsistant check if you want
    _gear_ratio = 1;                                // so wrong rn
    _angle_per_count = 360.0 / _counts_per_rev;     // so wrong rn
    _angle_per_rev = 360.0 * _gear_ratio;           // so wrong rn


    // motor state values
    _counts = 0;
    _angle_shaft = 0.0;
    _angle_tracker = 0.0;
    _dir = False;                                   // imma make CCW True and CW Flase
    _on = False;


    // set up pins
    pinMode(POWER0, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(DIR_REL01, OUTPUT);
    pinMode(ENCOD0, INPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);

    // set up interrupts
    attachInterrupt(ENCOD0, isrEncoder, FALLING);
    attachInterrupt(END00, isrEndstop00, FALLING);
    attachInterrupt(END01, isrEndstop01, FALLING);
}

void Motor::turnOn() {
    digitalWrite(POWER0, HIGH);
    _on = True;
}


void Motor::turnOff() {
    digitalWrite(POWER0, LOW);
    _on = False;
}


// I have to check this logic with the system
void Motor::setDirection(int dir) {
    if (dir == 0) {
        digitalWrite(DIR_REL00, HIGH);
        digitalWrite(DIR_REL01, LOW);
        _dir = False;                   // check if this is CW
    }
    else if (dir == 1) {
        digitalWrite(DIR_REL00, LOW);
        digitalWrite(DIR_REL01, HIGH);
        _dir = True;                    // check if this is CCW
    }
}

void Motor::moveAbsCount(int count) {
    // move to absolute count
    // count is in encoder counts

}

void Motor::moveRelCount(int count) {
    // move to relative count
    // count is in encoder counts
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

// getters
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

// setters
void Motor::setAngleShaft(float angle) {
    _angle_shaft = angle;
}

void Motor::setAngleTracker(float angle) {
    _angle_tracker = angle;
}

void Motor::setDirection(bool dir) {
    _dir = dir;
}

void Motor::setOn(bool on) {
    _on = on;
}


/*
NEED TO COME BACK TO THESE
*/
// interrupt service routines
void Motor::isrEncoder() {
    // update angle

    // if its CCW then add to count
    if (_dir) {
        _counts += 1;
        _angle = _counts * _angle_per_count;
    }
    // if its CW then subtract from the count
    else {
        _counts -= 1;
        _angle_shaft = _counts * _angle_per_count;
        _angle_tracker = _angle_shaft + _angle_tracker;     //idk whats going on here
    }
}

void Motor::isrEndstop00() {
    // update angle
    _angle_shaft = 0.0;
}

void Motor::isrEndstop01() {
    // update angle
    _angle_shaft = 360.0;
}