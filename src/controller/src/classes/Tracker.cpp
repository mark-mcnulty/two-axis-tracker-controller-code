#include "Tracker.h"
#include "Motor.h"
#include <Arduino.h>

Tracker::Tracker() {
    // Constructor
    pinMode(POWER0, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(DIR_REL01, OUTPUT);
    pinMode(ENCOD0, INPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);

    // Parameters Assumed to be P1, P2, P3, P4, P5 as in Fortran
    // pCount is num of parameters  

void Tracker::turnOn() {
    digitalWrite(POWER0, HIGH);
}

void Tracker::turnOff() {
    digitalWrite(POWER0, LOW);
}

void Tracker::trackSun() {
    if (PCOUNT >= 0) {
        pChk2(HCOUNT, PCOUNT, P1, P2, ERR);
        if (ERR == 0) {
            for (int I = static_cast<int>(P1); I <= static_cast<int>(P2); ++I) {
                HALT(I);
                HSTATE[I] = 5;
            }
        }
    }
    return;
}

void Tracker::coordHeli{
		if(PCOUNT == 4){
			int IP1 = -1;
			if(abs(P1) < 32767){
				IP1 = P1;
			}
		}
		if(IP1 > 1 && IP1 < HCOUNT){
			XHELIO(IP1) = P2f;
			YHELIO(IP1) =  P3;
			ZHELIO(IP1) = P4;
			SAVDAT();
		}
	return;
}

void Tracker::pChk2(int HCOUNT, int &PCOUNT, float &P1, float &P2, int &ERR) {
    if (PCOUNT == 0) {
        P1 = 1.0;
        P2 = HCOUNT;
        PCOUNT = 2;
    }

    if (PCOUNT == 1) {
        P2 = P1;
        PCOUNT = 2;
    }

    ERR = 0;

    if (PCOUNT != 2)       ERR = 1;
    if (P1 < 1.0)          ERR = 2;
    if (P1 > HCOUNT)       ERR = 3;
    if (P2 < 1.0)          ERR = 4;
    if (P2 > HCOUNT)       ERR = 5;
    if (P1 > P2)           ERR = 6;
}
}
