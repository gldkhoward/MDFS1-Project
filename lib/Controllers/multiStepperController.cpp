#include <multiStepperController.h>

MultiStepperController::MultiStepperController(Stepper* stepper1, Stepper* stepper2){
    stepper1_ = stepper1;
    stepper2_ = stepper2;
}


void MultiStepperController::run2Steppers(unsigned int delay){
    stepper1_->sendStepLow();
    stepper2_->sendStepLow();
    delayMicroseconds(delay);
    stepper1_->sendStepHigh();
    stepper2_->sendStepHigh();
    delayMicroseconds(delay);
}
/**
 * @brief Method that rotates 2 stepper motors based on inputs
 * 
 * @param delay Delay between stepper pulses (sets rotation speed)(us)
 * @param steps How man steps sent to the motor 
 * @param dir1 Rotation Direction of motor 1 
 * @param dir2 Rotation Direction of motor 2
 */
void MultiStepperController::rotate2Steppers(unsigned int delay, unsigned int steps, bool dir1, bool dir2){
    stepper1_->setDir(dir1);
    stepper2_->setDir(dir2);
    for(unsigned int i = 0; i < steps; i++){
        stepper1_->sendStepHigh();
        stepper2_->sendStepHigh();
        delayMicroseconds(delay); 
        stepper1_->sendStepLow();
        stepper2_->sendStepLow();
        delayMicroseconds(delay);
    }

}

void MultiStepperController::testStepper(){
    stepper1_->motorRun(500, 400, 1);
}