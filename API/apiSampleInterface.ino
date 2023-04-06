// Variables and constants

void setup() {
  Serial.begin(9600);
  Serial.println("Solar Tracker User Interface");

}

void loop() {
  // put your main code here, to run repeatedly:
  acceptCommand();
}

//Functions
void acceptCommand() {
  //List commands
  Serial.println("Avaible Commands");
  Serial.println("1: Go To");
  Serial.println("2: Stow");
  Serial.println("3: Display Data");
  Serial.println("Enter the number you wish to select");

  //Wait until user inputs
  while (Serial.available() == 0) {
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
      Serial.println("Displaying current Solar Tracker Data");
      Serial.println();
      printData();
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
  }

  int elevation = Serial.parseInt();

  Serial.println("Enter Azimuth");

  //Wait until user inputs
  while (Serial.available() == 0) {
  }

  int azimuth = Serial.parseInt();

  Serial.print("You entered ");
  Serial.print(elevation);
  Serial.print(" for elevation and ");
  Serial.print(azimuth);
  Serial.println(" as azimuth");

  //Later implement check to confirm

  //Send to M7
  checkRecieved();

  //See if user wants to see data
  choosePrintData();
}

void stow() {
  checkRecieved();

  //See if user wants to see data
  choosePrintData();
}

void printData() { 
  checkRecieved();

  Serial.println("Press any key to stop data");

  while (Serial.available() == 0) {
    //Get data from M7
    //Print data
    Serial.print("Date: foo, ");
    Serial.print("Time: foo, ");
    Serial.print("Elevation: foo, ");
    Serial.print("Azimuth: foo, ");
    Serial.print("Position: foo, ");
    Serial.println("Status: foo");

    //Wait 1 second
    //will replace with millis
    delay(1000);
  }
  Serial.println();
  
  char temp = Serial.read();
}

//Checks if M7 recieved command and functions
void checkRecieved() {
  Serial.println("Your command was recieved by the Solar Tracker");
}

//Checks if user wants to see data now
void choosePrintData() { 
  Serial.println("Would you like to see the Solar Tracker data?");
  Serial.println("Y = 1");
  Serial.println("N = 2");

  //Wait until user inputs
  while (Serial.available() == 0) {
  }

  char seeData = Serial.parseInt();

  switch (seeData) {
    case 1:
      printData();
      break;

    case 2:
      
      break;

    default:
      Serial.println("You did not choose a valid response, assuming no");
      Serial.println();
  }
}

