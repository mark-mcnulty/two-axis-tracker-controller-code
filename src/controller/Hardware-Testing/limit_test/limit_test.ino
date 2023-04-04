#define END0 PA_8     // pwm0     // endstop0
#define END1 PC_6     // pwm1     // endstop1


void setup(){
    pinMode(END1, INPUT);
    pinMode(END0, INPUT);
    Serial.begin(9600);
}

void loop(){
    Serial.println(digitalRead(END1));

}