void encoderISR();

#define PIN PK_1    // pwm5

int counter = 0;



void setup() {
  pinMode(PIN, INPUT); 
  attachInterrupt(PIN, encoderISR, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
}


void encoderISR(){
  counter++;
}
