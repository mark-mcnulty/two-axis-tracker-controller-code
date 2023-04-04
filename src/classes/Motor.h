#ifndef Motor_h
#define Motor_h


#include <Arduino.h>
#include "pin_def.h"

class Motor {
    private:
        // constants for motor
        int _counts_per_rev;
        float _gear_ratio;
        float _angle_per_count;
        float _angle_per_rev;

        // motor state values
        float _angle_shaft;
        float _angle_tracker;
        bool _dir;
        bool _on;

    public:
        Motor();
        void turnOn();
        void turnOff();
        void setDirection(int dir);
        void moveAbsAng(float angle);
        void moveRelAng(float angle);
        void moveAbsCount(int count);
        void moveRelCount(int count);

        // getters
        float getAngleShaft();
        float getAngleTracker();
        bool getDirection();
        bool getOn();

        // setters
        void setAngleShaft(float angle);
        void setAngleTracker(float angle);
        void setDirection(bool dir);
        void setOn(bool on);

        // interrupt service routines
        void isrEncoder();
        void isrEndstop00();
        void isrEndstop01();

}
#endif 