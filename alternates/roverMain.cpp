#include <Arduino.h>
//#include <hardware.h>
#include <cncShield.cpp>
#include <stepper.h>
#include <linearAcuator.h>
#include <limitSwitch.h>
#include <stepperConfigs.cpp>
#include <roverController.h>
#include <multiStepperController.h>

#include <zervo.h>

using namespace cncShield;
using namespace steppers;


Stepper leftWheel(x::dir, x::step);
Stepper rightWheel(y::dir, y::step);
Stepper payload(z::dir, z::step);

Zervo claw(pins::spnEn); 
MultiStepperController wheels(&leftWheel, &rightWheel);

LimitSwitch signal(pins::resume);

RoverController rover(&wheels, &payload, &claw); 
//RoverController rover(&leftWheel, &rightWheel, &payload, &claw);

void setup(){

    leftWheel.setup();
    rightWheel.setup();
    payload.setup();

    signal.setup();

    claw.setup();

    Serial.begin(9800);
    pinMode(enable, OUTPUT);
    digitalWrite(enable, LOW);
    
    pinMode(pins::coolEnable, OUTPUT);
    digitalWrite(pins::coolEnable, LOW);

}

void loop(){
    
    Serial.println(0);
    rover.moveForward(200);
    Serial.println("moved fowaard");
    delay(500);
    rover.clawPayloadPickup();
    Serial.println("grabbed");
    delay(1000);
    rover.moveBackward(400);
    Serial.println("moved back");

    
/*
    digitalWrite(pins::coolEnable, HIGH);
    delay(2000);
    digitalWrite(pins::coolEnable, LOW);
    */
    delay(45000);
    Serial.println("post delay");

    rover.moveForward(400);
    delay(2000);
    rover.clawPayloadDrop();
    delay(2000);
    rover.moveBackward(400);
    delay(2000); 

    exit(0);
}
