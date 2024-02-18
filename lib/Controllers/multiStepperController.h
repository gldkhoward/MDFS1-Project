#ifndef MULTISTEPPERCONTROLLER_H
#define MULTISTEPPERCONTROLLER_H 

#include <stepper.h>


class MultiStepperController{
    public:
        MultiStepperController(Stepper* stepper1, Stepper* stepper2);
        void run2Steppers(unsigned int delay); 
        void rotate2Steppers(unsigned int delay, unsigned int steps, bool dir1, bool dir2);
        void testStepper();

    private: 
        Stepper* stepper1_;
        Stepper* stepper2_;


};

#endif //MULTISTEPPERCONTROLLER_H