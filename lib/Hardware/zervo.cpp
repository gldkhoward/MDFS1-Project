#include "zervo.h" 


/**
 * @brief Servo Setup with basic 0 to 180 degree limits
 * 
 * @param pin Pin connected to the Servo Motor PWM wire
 */
Zervo::Zervo(unsigned int pin){
    pin_ = pin;
    upperLimit_ = 180;
    lowerLimit_ = 0;
    
    
}

/**
 * @brief Servo Setup with user defined limits
 * 
 * @param pin Pin connected to the Servo Motor PWM wire
 * @param upperLimit Upper degree limit of the Servo
 * @param lowerLimit Lower degree limit of the Servo
 */
Zervo::Zervo(unsigned int pin, unsigned short upperLimit, unsigned short lowerLimit){
    pin_ = pin;
    upperLimit_ = upperLimit;
    lowerLimit_ = lowerLimit;
}

/**
 * @brief Setup function for Servo Motor 
 */
void Zervo::setup(){
    pinMode(pin_, OUTPUT);
    servo_.attach(pin_);
    servo_.write(0);
}

/**
 * @brief Zervo method to turn motor to specific degree 
 * @param deg Angle to turn to (Degrees)
 */
void Zervo::turnToDeg(unsigned short deg){
    servo_.write(deg);
}
/**
 * @brief Zervo method to turn motor to its upper limit 
 */
void Zervo::upperLimit(){
    servo_.write(upperLimit_);
}
/**
 * @brief Zervo method to turn motor to its upper limit 
 */
void Zervo::lowerLimit(){
    servo_.write(lowerLimit_);
}