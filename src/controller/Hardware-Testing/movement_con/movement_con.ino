void encoderISR();
int counter = 0;

#define DIR_REL01 PG_7   //PWM 3     // dir_relay01
#define DIR_REL00 PJ_11   //PWM 4     // dir_relay00
#define POWER0 PA_0C   //ADC A0     // power_relay0
#define END00 PA_8     // pwm0     // endstop00
#define END01 PC_6     // pwm1     // endstop01
#define ENCOD0 PC_7     // pwm2     // encoder0


void setup(){
    pinMode(DIR_REL01, OUTPUT);
    pinMode(DIR_REL00, OUTPUT);
    pinMode(POWER0, OUTPUT);
    pinMode(END00, INPUT);
    pinMode(END01, INPUT);
    pinMode(ENCOD0, INPUT);

    attachInterrupt(ENCOD0, encoderISR, CHANGE);

    digitalWrite(DIR_REL01, HIGH);
    digitalWrite(DIR_REL00, LOW);
    
    digitalWrite(POWER0, HIGH);

    Serial.begin(9600);
}

void loop(){
    Serial.println(counter);
    if(counter >= 20) {
        // turn it off
        digitalWrite(POWER0, LOW);

        // wait one second
        delay(1000);

        // flip direction
        digitalWrite(DIR_REL00, HIGH);
        digitalWrite(DIR_REL01, LOW);

        // turn it on
        digitalWrite(POWER0, HIGH);

        // reset counter
        counter = 0;
    } else {

    }
}

void encoderISR(){
  counter++;
}