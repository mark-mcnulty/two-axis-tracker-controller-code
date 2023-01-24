void encoderISR();
int counter = 0;
int currentStateSig;
int previousStateSig;


void setup() {
  pinMode(SIGNAL_PIN, INPUT); 
  attachInterrupt(INTERRUPT_PIN, encoderISR, CHANGE);
  previousStateA = digitalRead(SIGNAL_PIN);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
}


void encoderISR(){
  
  currentStateSig = digitalRead(SIGNAL_PIN);
  
  if (currentStateSig != previousStateSig) {
    counter++;
    }
    previousStateSig = currentStateSig;
  }
