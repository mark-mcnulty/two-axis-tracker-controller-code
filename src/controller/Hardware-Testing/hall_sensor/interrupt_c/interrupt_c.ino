void encoderISR();

#define PIN PK_1    // pwm5

volatile int counter = 0;



void setup() {
  pinMode(PK_1, INPUT); 
  attachInterrupt(digitalPinToInterrupt(PK_1), encoderISR, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
}


void encoderISR(){
  counter++;
}
