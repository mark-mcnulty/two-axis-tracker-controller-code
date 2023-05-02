/*Code to Communicate between two cores in the Portenta H7. #ifdef statmenets are assigned to each core
Purpose for furture implementation is to tranfer data from our hardware code to the interface code
/*

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
    RPC.println("CORE 4 reading global variable " + 1234); // DOES NOT WORK as only one serial connection?

    //Sets M4 var
     int m4Var = 2;  

     //Calls M7 helper function and passes M4 var in
     auto res = RPC.call("setVar", m4Var).as<int>();
   
   #endif   
  
  //M7
   #ifdef CORE_CM7   
     Serial.println("---------------------------------");
     //Prints from M7 globaly defined variable
     Serial.println("M7 Initial Variable: 1234");
     //Prints M7 local variable that was changed by M4 hopefully
     Serial.println("From M4, showing changed M7 Variable: "+ String(m7IntGlobal));

    //Very confused by this part UNKNOWN
     while (RPC.available()) {
       Serial.println("In RPC avaible"); //Don't know why this does not enter
       Serial.write(RPC.read()); // check if the M4 has sent an RPC println ???
     }
   #endif

   delay(5000); // Wait for 5 seconds
}
