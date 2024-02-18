#ifndef ROVERCONTROLLER_H
#define ROVERCONTROLLER_H 

#include "stepper.h" 
#include "zervo.h" 
#include "limitSwitch.h"
#include "linearAcuator.h" 
#include <multiStepperController.h>

class RoverController{
    public: 
        RoverController(Stepper* leftWheel, Stepper* rightWheel, Stepper* payload, Zervo* claw);
        RoverController(MultiStepperController* wheels, Stepper* payload, Zervo* claw );
        void setup();

        void moveForward(int dist);
        void moveBackward(int dist);
        void rotate();
        
        void clawPayloadPickup();
        void clawPayloadDrop();
        void wedgePayloadPickup();
        void wedgePayloadDrop();


    private:
        Stepper* leftWheel_;
        Stepper* rightWheel_; 
        Stepper* payload_;
        Zervo* claw_;
        LimitSwitch* ground_;
        MultiStepperController* wheels_;

        bool leftWheelForward_ = 1; 
        bool leftWheelBack_ = 0;

        bool rightWheelForward_ = 0; 
        bool rightWheelBack_ = 1;

        bool payloadUp_ = 1; 
        bool payloadDown_ = 0;

};


#endif //ROVERCONTROLLER_H