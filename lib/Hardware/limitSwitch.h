#ifndef LIMITSWITCH_H
#define LIMITSWITCH_H

#include <Arduino.h>

class LimitSwitch{
    public:
        LimitSwitch(int pin);
        void setup();
        bool atLimit();
    private:
        int pin_; //private storage for Pin in
};

#endif //LIMITSWITCH_H

