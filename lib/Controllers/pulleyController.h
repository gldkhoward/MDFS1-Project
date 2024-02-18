#ifndef PULLEYCONTROLLER_H
#define PULLEYCONTROLLER_H

#include <stepper.h>
#include <limitSwitch.h>
#include <course.cpp>
#include <zervo.h>
#include <multiStepperController.h>
#include "stepperConfigs.cpp"

using namespace WarmanCourse;


class PulleyController{
    public:
        PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch, LimitSwitch* deposit, LimitSwitch* start, LimitSwitch* frontRover, LimitSwitch* rearRover);
        PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch, LimitSwitch* frontRover, LimitSwitch* rearRover);
        PulleyController(Stepper* pulley, Stepper* frontWinch, Stepper* rearWinch);
        PulleyController(Stepper* pulley, MultiStepperController* winch);

        bool liftRover();
        bool releaseRover();
        bool swapSides();
        bool depositZone();
        bool startZone();
        bool liftRoverStart();
        bool releaseRoverSimple();

        void pulleyTest();

    private:
        Zones location_;
        Stepper* pulley_;
        Stepper* frontWinch_;
        Stepper* rearWinch_;
        LimitSwitch* deposit_;
        LimitSwitch* start_;
        LimitSwitch* frontRover_;
        LimitSwitch* rearRover_;
        MultiStepperController* winch_;
        

        //Direction Variables for the pulley(may change due to physical placement)
        bool pulleyPosDelta_ = 1;
        bool pulleyNegDelta_ = 0; 
        bool winchUp_ = 0;
        bool winchDown_ = 1;
        double distPerRotation_ = (PI * PulleyWheel::diameter)/PulleyWheel::gearRatio; //Linear Distance moved per rotation 
        double ropeDist_ = 600;




};

#endif // PULLEYCONTROLLER_H