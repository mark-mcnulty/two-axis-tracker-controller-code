void encoderISR();
double cntsToDeg(int);
volatile int counter;
int countsPerRevolution;
#define PIN PK_1

void setup() {
  pinMode(PIN, INPUT); 
  attachInterrupt(digitalPinToInterrupt(PIN), encoderISR, FALLING);
  Serial.begin(9600);
  counter = 0;
  countsPerRevolution = ;
}

void loop() {
  double degreeCounts = cntsToDeg(counter);
  Serial.print(counter);
  Serial.print("      ");
  Serial.println(degreeCounts);  
}


void encoderISR() {
  counter++;
}


double cntsToDeg(int counts) {
  double degreeCounts;
  return degreeCounts = ((double)counts/(double)countsPerRevolution)*360;
}
