/*
  Web Server

 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)

 created 18 Dec 2009
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe
 modified 02 Sept 2015
 by Arturo Guadalupi
 
 */

#include <SPI.h>
#include <PortentaEthernet.h>
#include <Ethernet.h>
#include <ArduinoJson.h>
//#include <Arduino_PortentaBreakout.h>

// The IP address will be dependent on your local network:
// Update this to whatever it is via ipconfig in cmd prmpt
IPAddress ip(192, 168, 1, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP): 
// Might want to change this to whatever port
EthernetServer server(80);


void setup() {

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Ethernet WebServer Example");

  // start the Ethernet connection and the server:
  Ethernet.begin(ip);

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start the server
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  // compare the previous status to the current status
  EthernetClient client = server.available();
  
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
  
    while (client.connected()) {            // loop while the client's connected
     
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            //client.println("Connection: close");  // the connection will be closed after completion of the response
            // client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");

            // output the value of each analog input pin
            // need to define what analog inputs

            //This outputs data into html text file
            for (int analogChannel = 0; analogChannel < 5; analogChannel++) {
              int sensorReading = analogRead(analogChannel);
              //Only sends sensor reading
              client.print(sensorReading);
              client.println("<br />");
            }
            client.println("</html>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET")) {
          // Read data from analog pins
        }
        if (currentLine.endsWith("POST")) {
          //Get data from http POST request in currentLine
          
          
          // Write data to analog pins 
          //analogWrite(ANALOG_A0, );   
          //analogWrite(ANALOG_A0, HIGH);             
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
  
}