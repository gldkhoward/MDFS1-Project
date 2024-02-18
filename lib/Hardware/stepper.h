#ifndef STEPPER_H
#define STEPPER_H

#include "Arduino.h"

/**
 * @brief Class for constructing Stepper Motor object
 * 
 */
class Stepper{
    public:
        Stepper(int dirPin, int stepPin);
        Stepper(int dirPin, int stepPin, int stepsPerRev);

        void setup();
        
        void motorRun(unsigned int delay, unsigned int steps, bool dir);
        
        //setDir and step methods should be used in conjunction with eachother
        void setDir(bool dir);
        void step(unsigned int delay);

        void setStepsPerRev(unsigned int stepsPerRev);

        void sendStepHigh();
        void sendStepLow();

        void stepperTest();

    private:
        int dirPin_; //Private storage of dirPin
        int stepPin_; //Private storage of stepPin
        int stepsPerRev_; //Private storage of steps per rev for motor
        bool dirState_;
};

#endif //STEPPER_H
