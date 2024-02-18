#include <Arduino.h>
//#include <hardware.h>
#include <cncShield.cpp>
#include <stepper.h>
#include <linearAcuator.h>
#include <limitSwitch.h>
#include <stepperConfigs.cpp>
#include <pulleyController.h>
#include <multiStepperController.h>

#include <zervo.h>

using namespace cncShield;
using namespace steppers;


//Setting up project modes:
unsigned int mode = 0;
#define STARTUPMODE 0
#define RETRIEVEMODE 1
#define WINCHMODE 2


#define HARDMODE 10

#define TESTMODE 11

bool testEnable = 0;

//Setting up stepper motors:

Stepper pulley(x::dir, x::step);
Stepper frontWinch(y::dir, y::step);
Stepper rearWinch(z::dir, z::step);


   
//Setting up limit Switches:
LimitSwitch pulleyStart(x::limit);
LimitSwitch pulleyEnd(y::limit);

LimitSwitch roverSignal(pins::resume);

MultiStepperController winch(&frontWinch, &rearWinch);
PulleyController pulleySystem(&pulley, &winch);
//PulleyController pulleySystem(&pulley, &frontWinch, &rearWinch);

//PulleyController pulleySystem(&pulley, &frontWinch, &rearWinch, &frontRover, &rearRover); MORE ADVANCED 

void setup() {
  //Arduino Stepper setup:
  pulley.setup();
  frontWinch.setup();
  rearWinch.setup();

  //Arduino limit setup:
  
  pulleyStart.setup();
  pulleyEnd.setup();

  roverSignal.setup();

  Serial.begin(9800);
  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);
  pinMode(pins::coolEnable, OUTPUT);
  digitalWrite(pins::coolEnable, LOW);

  if(testEnable) mode = TESTMODE;

  mode = HARDMODE;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("begun");
  switch (mode)
   {
    case STARTUPMODE:
      break;

    case RETRIEVEMODE:
      break;

    case HARDMODE:
      
      delay(10000);
      
        
      
      pulleySystem.liftRover();
      delay(500);
      pulleySystem.swapSides();
      delay(500);
      pulleySystem.releaseRover();
 
      delay(10000);

      
      delay(1000);
      pulleySystem.liftRover();
      delay(1000);
      pulleySystem.swapSides();
      delay(1000);
      pulleySystem.releaseRover();
      break;
      

    case TESTMODE:
      pulleySystem.swapSides();
  
      break;

   default:
     break;
   }

   exit(0);  
  

}