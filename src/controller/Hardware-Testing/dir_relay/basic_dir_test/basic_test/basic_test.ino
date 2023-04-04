#define DIR_REL01 PG_7   //PWM 3     // dir_relay01
#define DIR_REL00 PJ_11   //PWM 4     // dir_relay00

void setup() {
    pinMode(DIR_REL01, OUTPUT); 
    pinMode(DIR_REL00, OUTPUT); 
}

void loop() {

    // set direction
  digitalWrite(DIR_REL01, HIGH);
  digitalWrite(DIR_REL00, LOW);
  delay(5000);

    //set direction
  digitalWrite(DIR_REL01, LOW);
  digitalWrite(DIR_REL00, HIGH);
  delay(5000);

}