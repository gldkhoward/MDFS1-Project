#ifndef SERVO_H
#define SERVO_H 

#include <Arduino.h>
#include <Servo.h>

class Zervo{
    public:
        Zervo(unsigned int pin);
        Zervo(unsigned int pin, unsigned short upperLimit, unsigned short lowerLimit);

        void turnToDeg(unsigned short deg);
        void upperLimit();
        void lowerLimit();

        void setup();

    private:
        unsigned int pin_;
        unsigned int upperLimit_;
        unsigned int lowerLimit_;
        Servo servo_;

};

#endif // SERVO_H