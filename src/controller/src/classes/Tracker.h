// LED.h
#ifndef Tracker_h
#define Tracker_h

#include <Arduino.h>
#include "pin_def.h"



class Tracker {
    private:
      bool _dir;
      bool _on;
      // tracking position
      int _counts;  // number of encoder counts 
      float _angle; // angle of the tracker


    public:
        Tracker();
        void turnOn();
        void turnOff();
        void setDirection(int dir);
        void moveAbs(float angle);
        void moveRel(float angle);

        // interrupt service routines
        void isrEncoder();
        void isrEndstop00();
        void isrEndstop01();
};

#endif 