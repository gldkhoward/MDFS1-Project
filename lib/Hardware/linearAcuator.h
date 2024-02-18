#ifndef LINEARACTUATOR_H
#define LINEARACTUATOR_H

#include <Arduino.h>

class LinearActuator{
    public: 
        LinearActuator(unsigned int pin);

        void setup();
        void actuate();
        void retract();

    private:
        unsigned int pin_;
};

#endif // LINEARACTUATOR_H