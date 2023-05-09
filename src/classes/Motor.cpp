#include "Motor.h"
#include "Arduino.h"


/*
CONSTRUCTOR 

Parameters:
    axis: the axis of the motor. either "Az" or "El". Note this doesn't work because of the way the pin calls are for the Portenta. 
          I have to make two motor classes and two motor objects.

returns:
    none

description:
    This sets up the class needs to be called to use the motor. 
*/
Motor::Motor(String axis) {
    // global values
    // constructor 
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

/*
turnOn()

parameters:
    none

returns:
    none

description:
    This turns on the motor.
*/
void Motor::turnOn() {
    // turn on the motor/power relay 
    digitalWrite(POWER0, HIGH);

    // set the status flag to on
    _on = true;
}

/*
turnOff()

parameters:
    none

returns:
    none

description:
    This turns off the motor.
*/
void Motor::turnOff() {
    // turn off the motor/power relay
    digitalWrite(POWER0, LOW);

    // set the status flag to off
    _on = false;
}

/*
setDirection(bool dir)

parameters:
    dir: the direction to set the motor to. true is CCW and false is CW. However, I don't think I got around to testing if CW and CCW are correct.

returns:
    none

description:    
    This sets the direction of the motor. By raising two pins high or low. This raises the direction pins high and low to set the direction of the motor.
*/
// I have to check this logic with the system
void Motor::setDirection(bool dir) {
    if (dir == false) {
        // need the two direction pins to be opposite
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

/*
moveAbsCount(int abs_desired)

parameters:
    abs_desired: the absolute count to move the motor to.

returns:
    none

description:
    This function will move the motor to the absolute count. This is the count from the beginning of the program.
    the count at the beginning of the program is 0. So if you move 100 counts and then say moveAbsCount(0) it will move the motor back to the home position.
*/
void Motor::moveAbsCount(int abs_desired) {
    // figure out where we are relative to the desired count
    int desired = abs_desired - _total_counts;

    // move to the desired count
    moveRelCount(desired);
}

/*
moveRelCount(int desired)

parameters:
    desired: the relative count to move the motor to based on current location. 

returns:
    none

description:  
    This function will move the motor to the count position relative to its current position. so if you are at 100 counts and you say moveRelCount(-10) it will move the motor to 90 counts from the beginning of the program.
    Or anther way of thinking about it is if you call moveRelCount(10) it will move the motor 10 counts from its current position.
    This is the main function that you will be dealing with. All the other functions can be derived from this one and if you look at the other 
    movement functions you can see that I use this function a lot. This is the bread and butter function of movement.  
*/
void Motor::moveRelCount(int desired) {
    _counts = 0;
    _moving = true;
    _counts_desired = desired;

    // re-assign the total counts this is the parameter that
    // keeps track of the total counts the motor has moved since 
    // the program started
    _total_counts += desired;

    
    // check that dir is set right
    if (desired > 0) {
      setDirection(true);
    } else {
      setDirection(false);

      // we cant keep track of negative counts so we need to make it positive
      // the system only knows when the hall sensor is getting hit and not the direction
      desired *= -1;
    }

    // turn on the motor
    turnOn();

    // wait for the motor to get to the desired count
    while(_counts <= desired){
        delay(10);
    }

    // turn off the motor
    turnOff();
}
// doesn't keep track of the rounded number
/*
moveRelAngTracker(float angle)

parameters:
    angle: This is the angle you want to move the tracker itself. this should take into account the gear ratio.

returns:
    none

description:
    This moves the tracker to the relative angle that is inputted. This will move the tracker the amount of degrees inputted.
    from its current location.

NOTES: 
    This still needs to take into account the amount of degrees that the inputted number has been rounded. If the angle inputted is not a multiple of the 
    gear ratio and the counts per rev then the tracker will not move the correct amount of degrees and will round to the nearest multiple of the gear ratio
    thus loosing by the amount that was rounded. 
*/
void Motor::moveRelAngTracker(float angle) {
    // find the number of counts to move
    int desiredCount = (int) (angle / _angle_per_count);

    // move to the desired count
    moveRelCount(desiredCount);
}

/*
moveAbsAngTracker(float angle)

parameters:
    angle: This is the angle you want to move the tracker itself. this should take into account the gear ratio. 

returns: 
    none

description:
    this will move the tracker to the absolute angle that is inputted. This will move the tracker the amount of degrees inputted.
    from the beginning of the program. So if you currently are at 50deg az or el and you say go to 30 deg az or el it will move the tracker to 30 deg az or el.
*/
void Motor::moveAbsAngTracker(float angle) {
    // move to absolute angle
    // angle is in degrees
    // angl
}

//NEEDS WORK
/* 
moveAbsAng(float angle)

parameters:
    angle: the absolute angle to move the motor shaft (this is different from the tracker). this is just the angle of the shaft. 
           each count is equal to 360/10 = 36 degrees. it is defined above in the constructor. This moves to the position of the shaft. 
           from the zero point which is the begging of the program. at the beginnging of the program the shaft is at 0 degrees. so if you move 
           100 counts and then say moveAbsAng(0) it will move the shaft back to the home position as when it started.

returns:
    none

description:
    This moves the motor to the absolute angle. 

NOTE: 
    This needs to be built out. I would employ the use of moveRelCount() to move the motor to the absolute angle.
*/
void Motor::moveAbsAng(float angle) {
    // move to absolute angle
    // angle is in degrees
    // angl
}
//NEEDS WORK
/* 
moveRelAng(float angle)

parameters:
    angle: the relitive angle to move the motor shaft (this is different from the tracker). this is just the angle of the shaft. 
           each count is equal to 360/10 = 36 degrees. it is defined above in the constructor.

returns:
    none

description:
    This moves the motor to the absolute angle. 

NOTE: 
    This needs to be built out. I would employ the use of moveRelCount() to move the motor to the absolute angle.
*/
void Motor::moveRelAng(float relAngle) {
    // find the number of counts to move
    // int desired = relAngle % _angle_per_count;      // we have to take the modulus of the angle to get actual because we can only go in multiples of the angle per count
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
    // if the encoder gets triggered we need to update the motor classes count 
    // based on the direction the motor is rotating
    _counts++;
}

void Motor::isrEndstop00(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();
}

void Motor::isrEndstop01(){
    // if the end-stop gets triggered we need to turn off the motor
    turnOff();
}


// void Motor::handle_event() {
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


