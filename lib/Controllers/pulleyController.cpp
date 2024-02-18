#include "pulleyController.h"
 
using namespace steppers;

/**
 * @brief Construct a new Pulley Controller:: Pulley Controller object
 * 
 * @param pulley The driving pulley Stepper motor
 * @param frontWinch The Front Winch Stepper Motor
 * @param rearWinch The Rear Winch Stepper Motor
 * @param deposit Limit Switch setup for Deposit Zone
 * @param start Limit Switch setup for Start Zone
 * @param frontRover Limit Switch setup for the front on the Rover
 * @param rearRover Limit Switch setup for Rear of the Rover
 */
PulleyController::PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch, LimitSwitch* deposit, LimitSwitch* start, LimitSwitch* frontRover, LimitSwitch* rearRover){
    pulley_ = pulley; 
    frontWinch_ = frontWinch;
    rearWinch_ = rearWinch;
    deposit_ = deposit; 
    start_ = start;
    frontRover_ = frontRover;
    rearRover_ = rearRover;
    location_ = Zones::START;
}

/**
 * @brief Construct a new Pulley Controller:: Pulley Controller object with more limited functionality
 * 
 * @param pulley The driving pulley Stepper motor
 * @param frontWinch The Front Winch Stepper Motor
 * @param rearWinch The Rear Winch Stepper Motor
 * @param frontRover Limit Switch setup for the front on the Rover
 * @param rearRover Limit Switch setup for Rear of the Rover
 */
PulleyController::PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch, LimitSwitch* frontRover, LimitSwitch* rearRover){
    pulley_ = pulley; 
    frontWinch_ = frontWinch;
    rearWinch_ = rearWinch;
    frontRover_ = frontRover;
    rearRover_ = rearRover;
    location_ = Zones::START; 
}
/**
 * @brief Most basic construction of a pulley object
 * 
 * @param pulley The driving pulley Stepper motor
 * @param frontWinch The Front Winch Stepper Motor
 * @param rearWinch The Rear Winch Stepper Motor
 */
PulleyController::PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch){
    pulley_ = pulley; 
    frontWinch_ = frontWinch;
    rearWinch_ = rearWinch;
    location_ = Zones::START; 
}

PulleyController::PulleyController(Stepper* pulley, MultiStepperController* winch){
    pulley_ = pulley; 
    winch_ = winch;
    location_ = Zones::START; 
}




/**
 * @brief Function that moves the pulley to the deposit zone
 * 
 * @return true Reached the deposit Zone
 * @return false Timeout
 */
bool PulleyController::depositZone(){
    if(deposit_->atLimit() or location_ == Zones::DEPOSIT){
        location_ == Zones::DEPOSIT;
        return true;
    }
    else{
        pulley_->setDir(pulleyPosDelta_);
        location_ == Zones::CHASM;
        while(!deposit_->atLimit()){
            pulley_->motorRun(500, 10, 1);
        }
        location_ == Zones::DEPOSIT;
        return true;
    }
}

/**
 * @brief Function that moves the pulley to the start zone
 * 
 * @return true Reached the Start Zone
 * @return false Timeout
 */
bool PulleyController::startZone(){
    if(start_->atLimit() or location_ == Zones::START){
        location_ == Zones::START;
        return true;
    }
    else{
        pulley_->setDir(pulleyNegDelta_);
        location_ == Zones::CHASM;
        while(!start_->atLimit()){
            pulley_->step(700);
        }
        location_ == Zones::START;
        return true;
    }
}

/**
 * @brief Tests main pulley functionality
 * 
 */
void PulleyController::pulleyTest(){
    pulley_->stepperTest();
}

bool PulleyController::swapSides(){
    unsigned int steps = (ropeDist_/distPerRotation_)*Nema59Ncm::stepsPerRev;

    if(location_ == Zones::START){
        pulley_->motorRun(2000, 10000, 1);
        location_ = Zones::DEPOSIT;
        return true;
     }

     else if(location_ == Zones::DEPOSIT){
        pulley_->motorRun(2000, 10000, 0);
        location_= Zones::START;
        return true;
     }
     else{
        return false; 
     }
}

bool PulleyController::liftRoverStart(){
    winch_->rotate2Steppers(1500, int(Winch::steps*5), winchUp_, winchDown_);
    return true;
}


bool PulleyController::liftRover(){
    winch_->rotate2Steppers(1700, 4200, 1, 0);
    return true;
}

bool PulleyController::releaseRover(){
    winch_->rotate2Steppers(1000, 4200, 0, 1);
    return true;
}

bool PulleyController::releaseRoverSimple(){
    winch_->rotate2Steppers(600, int(Winch::steps * 0.25), winchDown_, winchUp_);
    return true;
}