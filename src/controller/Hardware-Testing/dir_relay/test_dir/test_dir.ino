#define DIR_REL01 PG_7   //PWM 3     // dir_relay01
#define DIR_REL00 PJ_11   //PWM 4     // dir_relay00
#define POWER0 PA_0C   //ADC A0     // power_relay0
#define END00 PK_1     // pwm0     // endstop00
#define END01 PH_15     // pwm1     // endstop01
#define ENCOD0 PC_7     // pwm2     // encoder0

#define D1 PK_1     // pwm5
#define D0 PH_15    // pwm6

void setup(){
    pinMode(DIR_REL01, OUTPUT); 
    pinMode(DIR_REL00, OUTPUT); 
    pinMode(POWER0, OUTPUT);
    digitalWrite(POWER0, LOW);
    Serial.begin(9600);
    // digitalWrite(PIN, HIGH);
}

void loop(){
  digitalWrite(POWER0, LOW);
  delay(1000);

  // set direction
  digitalWrite(DIR_REL01, HIGH);
  digitalWrite(DIR_REL00, LOW);
  // turn motor on
  digitalWrite(POWER0, HIGH);
  Serial.write("HIGH\n");
  delay(5000);

  // turn motor off
  digitalWrite(POWER0, LOW);
  delay(1000);


  Serial.write("LOW\n");
  digitalWrite(DIR_REL01, LOW);
  digitalWrite(DIR_REL00, HIGH);

  // turn on motor
  digitalWrite(POWER0, HIGH);
  delay(5000);
}