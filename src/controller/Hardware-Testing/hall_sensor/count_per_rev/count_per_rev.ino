void encoderISR();

#define ENCOD0 PC_7     // pwm2     // encoder0

int counter = 0;



void setup() {
  pinMode(ENCOD0, INPUT); 
  attachInterrupt(ENCOD0, encoderISR, CHANGE);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
}


void encoderISR(){
  counter++;
}
