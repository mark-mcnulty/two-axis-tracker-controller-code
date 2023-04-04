#define DIR_REL01 PG_7   //PWM 3     // dir_relay01
#define DIR_REL00 PJ_11   //PWM 4     // dir_relay00
#define POWER0 PA_0C   //ADC A0     // power_relay0

void setup(){
    pinMode(POWER0, OUTPUT); 
    digitalWrite(POWER0, HIGH);
}

void loop(){
  Serial.println(POWER0);
}