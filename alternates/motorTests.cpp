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



//Setting up stepper motors:

Stepper xMotor(x::dir, x::step);
Stepper yMotor(y::dir, y::step);
Stepper zMotor(z::dir, z::step);

MultiStepperController winches(&yMotor, &zMotor);

Zervo claw(pins::spnEn);


   
//Setting up limit Switches:
LimitSwitch pulleyStart(x::limit);
LimitSwitch pulleyEnd(y::limit);

LimitSwitch roverSignal(pins::resume);


void setup() {
  //Arduino Stepper setup:
  xMotor.setup();
  zMotor.setup();
  yMotor.setup();

  claw.setup();

  

  //Arduino limit setup:
  
  pulleyStart.setup();
  pulleyEnd.setup();

  roverSignal.setup();

  Serial.begin(9800);
  pinMode(enable, OUTPUT);
  digitalWrite(enable, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("begun");
  //xMotor.motorRun(1000, 1200, 1);
  winches.rotate2Steppers(400, int(Winch::steps * 0.75), 1, 0);
  winches.rotate2Steppers(1500, int(Winch::steps*0.25), 1, 0);
  //yMotor.motorRun(1000, 400, 1); 
  delay(5000);
  //xMotor.motorRun(1000, 1200, 0);
  //zMotor.motorRun(1000, 400, 1); 
 

}