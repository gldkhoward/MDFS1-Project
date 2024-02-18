#include <linearAcuator.h>

/**
 * @brief Construct a new Linear Actuator:: Linear Actuator object
 * 
 * @param pin Pin Actuator is connected to
 */
LinearActuator::LinearActuator(unsigned int pin){
    pin_ = pin;
}

/**
 * @brief Method for linear actuator setup
 * 
 */
void LinearActuator::setup(){
    pinMode(pin_, LOW);
}

/**
 * @brief Method to actuate actuator
 * 
 */
void LinearActuator::actuate(){
    digitalWrite(pin_, HIGH);
}

/**
 * @brief Method to retract actuator
 * 
 */
void LinearActuator::retract(){
    digitalWrite(pin_, LOW);
}
