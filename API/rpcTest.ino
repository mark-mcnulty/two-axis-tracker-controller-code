/*
 * my02-Dual-Core for the Portenta H7
 *
 * This code can be loaded on either core.
 * The M7 core will initialize the M4 core
 * The M7 will flash Blue randomly (under 6 seconds)
 * The M7 core will serial print its own messges
 * The M7 core will serial print messages it receives from the M4 core
 * The M7 core will continuously print the "myIntGlobal" variable
 *
 * Note: The M4 core will not compile unless -fexceptions is added 
 * to the bottom of the files: 
 * cflags.txt
 * cxxflags.txt 
 * at
 * C:\Users\<USER>\AppData\Local\Arduino15\packages\arduino-beta\hardware\mbed\1.2.2\variants\PORTENTA_H7_M4
 *
 * Note: AppData is hidden so find it directly
 * 
 * updated August 2nd, 2020
 * by Jeremy Ellis
 * Twitter @rocksetta
 * Website https://www.rocksetta.com
 *
*/

//Global
#include "RPC.h"  

//Test global variable to see if M4 can read it, UNKNOWN currently
int myIntGlobal = 8 ;

//On M7
#ifdef CORE_CM7

  // Set an M7 variable
  int m7IntGlobal = 1234;

  //Helper function
  int setVar(int a) {
    m7IntGlobal = (int)a;
    return a;
  }

#endif


void setup() {
  //Begin communication between cores
   RPC.begin();
   
   //On M7
  #ifdef CORE_CM7  
    //Boot M4
     LL_RCC_ForceCM4Boot();  //UNKNOWN how this is different from bootM4();

     //Begin Serial connection
     Serial.begin(115200);

     //Bind functions between cores
     RPC.bind("setVar", setVar); // IDK WHAT THIS DOES
  
  #endif 
   
}

void loop() {
   
   //M4
   #ifdef CORE_CM4  
    //Checks if M4 can read global var
    RPC.println("CORE 4 reading global variable " + String(myIntGlobal)); // DOES NOT WORK as only one serial connection?

    //Sets M4 var
     int m4Var = 2;  

     //Calls M7 helper function and passes M4 var in
     auto res = RPC.call("setVar", m4Var).as<int>();
   
   #endif   
  
  //M7
   #ifdef CORE_CM7   
     Serial.println("---------------------------------");
     //Prints from M7 globaly defined variable
     Serial.println("From M7 showing global variable: "+ String(myIntGlobal));
     //Prints M7 local variable that was changed by M4 hopefully
     Serial.println("From M7 showing changed variable: "+ String(m7IntGlobal));

    //Very confused by this part UNKNOWN
     while (RPC.available()) {
       Serial.println("In RPC avaible"); //Don't know why this does not enter
       Serial.write(RPC.read()); // check if the M4 has sent an RPC println ???
     }
   #endif

   delay(5000); // Wait for 5 seconds
}