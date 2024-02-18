#include "limitSwitch.h"

/**
* @brief Construct a new limitSwitch object
* 
* @param pin The output pin of the stepper attached to the Arduino
*/
LimitSwitch::LimitSwitch(int pin){
    pin_ = pin;
}

/**
* @brief limitSwitch method to check if switch has been trigged
* @return Returns true if switch is at a limit (is pressed)
*/
bool LimitSwitch::atLimit(){
    
    return digitalRead(pin_); //may need to be inverted
}

/**
 * @brief LimitSwitch setup method for the Arduino setup section
 */
void LimitSwitch::setup(){
    pinMode(pin_, INPUT);
}
