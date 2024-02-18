#include "stepper.h"

/**
 * @brief Construct a new default stepper object
 * 
 * @param dirPin Direction Pin attached to stepper
 * @param stepPin Step Pin attached to stepper
 */
Stepper::Stepper(int dirPin, int stepPin){
    dirPin_ = dirPin;
    stepPin_ = stepPin;
    stepsPerRev_ = 200; //Standard default steps per revolution for full stepping
}

/**
 * @brief Construct a new stepper object with stepsPerRev
 * 
 * @param dirPin Direction Pin attached to stepper
 * @param stepPin Step Pin attached to stepper
 * @param stepsPerRev Steps per revolution for stepper motor
 */
Stepper::Stepper(int dirPin, int stepPin, int stepsPerRev){
    dirPin_ = dirPin;
    stepPin_ = stepPin;
    stepsPerRev_ = stepsPerRev;
}

/**
 * @brief Stepper setup method for the Arduino setup section
 */
void Stepper::setup(){
    pinMode(dirPin_, OUTPUT);
    pinMode(stepPin_, OUTPUT);
}

/**
 * @brief Basic stepper method to control movement
 * 
 * @param delay Delay period of the steps (Controls Speed)
 * @param steps How many steps to be sent to the motor (Controls Angular Distance)
 * @param dir Specifies the diection the Stepper should spin (CW or CCW)
 */
void Stepper::motorRun(unsigned int delay, unsigned int steps, bool dir){
    digitalWrite(dirPin_, dir);
    dirState_ = dir;
    for(unsigned int i = 0; i < steps; i++){
        digitalWrite(stepPin_, HIGH);
        delayMicroseconds(delay);
        digitalWrite(stepPin_, LOW);
        delayMicroseconds(delay);
    }
}

/**
 * @brief Sets direction of movement for the stepper
 * 
 * @param dir Direction of roation
 */
void Stepper::setDir(bool dir){
   
    digitalWrite(dirPin_, dir);
    
}

/**
 * @brief Moves the stepper motor one step in current direction
 * 
 * @param delay Delay period of the steps (Controls Speed)
 */
void Stepper::step(unsigned int delay){
    digitalWrite(stepPin_, HIGH);
    delayMicroseconds(delay);
    digitalWrite(stepPin_, LOW);
    delayMicroseconds(delay);
}



void Stepper::setStepsPerRev(unsigned int stepsPerRev){
    stepsPerRev_ = stepsPerRev;
}

void Stepper::sendStepHigh(){
    digitalWrite(stepPin_, HIGH);
}

void Stepper::sendStepLow(){
    digitalWrite(stepPin_, LOW);
}

void Stepper::stepperTest(){
    digitalWrite(dirPin_, 1);
    for(unsigned int i = 0; i < 400; i++){
        digitalWrite(stepPin_, HIGH);
        delayMicroseconds(400);
        digitalWrite(stepPin_, LOW);
        delayMicroseconds(400);
    }
}