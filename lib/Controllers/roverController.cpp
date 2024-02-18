#include "roverController.h" 

RoverController::RoverController(Stepper* leftWheel, Stepper* rightWheel, Stepper* payload, Zervo* claw){
    leftWheel_ = leftWheel;
    rightWheel_ = rightWheel;
    claw_ = claw;
    payload_ = payload;
    claw_->turnToDeg(0);
}

RoverController::RoverController(MultiStepperController* wheels, Stepper* payload, Zervo* claw){
    wheels_ = wheels;
    claw_ = claw;
    payload_ = payload;
    claw_->turnToDeg(0);
}

void RoverController::moveForward(int dist){
    wheels_->rotate2Steppers(2000, dist, leftWheelForward_, rightWheelForward_);
}

void RoverController::moveBackward(int dist){
    wheels_->rotate2Steppers(2000, dist, leftWheelBack_, rightWheelBack_);
}

void RoverController::clawPayloadPickup(){
    claw_->turnToDeg(40);
    delay(1000);
    payload_->motorRun(3000, 200, payloadUp_);
}

void RoverController::clawPayloadDrop(){
    
    payload_->motorRun(3000, 200, payloadDown_);
    delay(1000); 
    claw_->turnToDeg(0);
    delay(1000);
    
}

