#include "Tracker.h"



Tracker::Tracker() {
    // Constructor
    pinMode(POWER0, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(DIR_REL01, OUTPUT);
    pinMode(ENCOD0, INPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);
}

void Tracker::turnOn() {
    digitalWrite(POWER0, HIGH);
}

void Tracker::turnOff() {
    digitalWrite(POWER0, LOW);
}