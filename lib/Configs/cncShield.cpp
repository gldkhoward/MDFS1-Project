#ifndef CNCSHIELD_CPP
#define CNCSHIELD_CPP

//source: https=//wiki.keyestudio.com/Ks0160_keyestudio_CNC_Shield_V3

#include <Arduino.h>

namespace cncShield
{
    namespace x {
        enum
        {
            step = 2,
            dir = 5,
            limit = 9
        };
    };
    namespace y
    { 
        enum
        {
            step = 3,
            dir = 6,
            limit = 10
        };
    };
        
    namespace z 
    {
        enum 
        {
            step = 4,
            dir = 7,
            limit = 11
        };
    }
    
    enum pins
    {
        enable = 8,
        xStep = 2,
        xDir = 5,
        yStep = 3,
        yDir = 6,
        zStep = 4,
        zDir = 7,
        xLimit = 9,
        yLimit = 10,
        zLimit = 11,
        spnEn = 12, 
        spnDir = 13, 
        coolEnable = A3,
        abort = A0,
        hold = A1, 
        resume = A2,
    };
};

#endif //CNCSHIELD.CPP