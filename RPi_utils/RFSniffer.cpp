/*
  RF_Sniffer
  
  Hacked from http://code.google.com/p/rc-switch/
  
  by @justy to provide a handy RF code sniffer
*/

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>     
     
RCSwitch mySwitch;
 

void handleMsg(){
      if (mySwitch.available()) {
        int value = mySwitch.getReceivedValue();
        if (value == 0) {
          printf("Unknown encoding");
        } else {    
          printf("Received %i\n", mySwitch.getReceivedValue() );
        }
        mySwitch.resetAvailable();
      }
}

int main(int argc, char *argv[]) {
  
	// This pin is not the first pin on the RPi GPIO header!
	// Consult https://projects.drogon.net/raspberry-pi/wiringpi/pins/
	// for more information.
	int PIN = 2;

	if(wiringPiSetup() == -1)
	return 0;

	mySwitch = RCSwitch();
	mySwitch.enableReceive(PIN,&handleMsg);  // Receiver on inerrupt 0 => that is pin #2
     
    
       while(1) {
         //handleMsg();

         std::string line;
         std::getline(std::cin, line);  // read a line from std::cin into line
         //std::cout << "Your Line Was (" << line << ")\n";
         //std::getline(std::cin, line);  
	 if(line == "q"){
		break;
	 }

       }

	exit(0);
}

