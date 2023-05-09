// Variables and constants
unsigned long previousMillis = 0; // For storing uptime
const long INTERVAL = 5000;
bool boolData = true;

void setup() {
  Serial.begin(9600);
  Serial.println("Solar Tracker User Interface: Accepting Commands while Printing");
}

void loop() {
  
  //List commands
  Serial.println("Avaible Commands");
  Serial.println("1: Go To");
  Serial.println("2: Stow");
  Serial.println("3: Print Data");
  Serial.println("Enter the number you wish to select");

  //Wait until user inputs
  //Prints Data if flag is true
  while (Serial.available() == 0) {
    printData();
  }

  //Get input
  int selection = Serial.parseInt();

  //Print empty line for readablitiy 
  Serial.println();

  switch (selection) {
    case 1:
      //Go to
      Serial.println("Go to has been selected");
      Serial.println();
      goTo();
      break;

    case 2:
      //Stow
      Serial.println("Stowing the Solar Tracker");
      Serial.println();
      stow();
      break;

    case 3:
      //Stow
      Serial.println("Toggling Print Data");
      Serial.println();
      togglePrintData();
      break;

    default:
      Serial.println("Please choose a valid selection from the list");
      Serial.println();
  }
}

//Functions for commands
void goTo() { 
  //Accept user input for Elevation and Azimuth
  Serial.println("Enter Elevation");

  //Wait until user inputs
  while (Serial.available() == 0) {
    printData();
  }

  int elevation = Serial.parseInt();

  Serial.println("Enter Azimuth");

  //Wait until user inputs
  while (Serial.available() == 0) {
    printData();
  }

  int azimuth = Serial.parseInt();

  //Print back inputs
  Serial.print("You entered ");
  Serial.print(elevation);
  Serial.print(" for elevation and ");
  Serial.print(azimuth);
  Serial.println(" as azimuth");

}

void stow() {
  //Send stuff to other core
  Serial.print("STOW");
}

void togglePrintData() { 
  boolData = !boolData;
}

//If boolData is true and it is time, print data to serial
void printData() {
  //Get current time
  unsigned long currentMillis = millis(); 

  if (boolData && (currentMillis - previousMillis >= INTERVAL)) {

    //Update time
    previousMillis = currentMillis;

    //Print data
   Serial.print("Date: foo, ");
   Serial.print("Time: foo, ");
   Serial.print("Elevation: foo, ");
   Serial.print("Azimuth: foo, ");
   Serial.print("Position: foo, ");
   Serial.println("Status: foo");
   Serial.println();
  }
}

