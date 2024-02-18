/* Sources
*   57Ncm Motor: https://www.omc-stepperonline.com/nema-17-bipolar-59ncm-84oz-in-2a-42x48mm-4-wires-w-1m-cable-connector-17hs19-2004s1
*
*/

#ifndef STEPPERCONFIGS_CPP 
#define STEPPERCONFIGS_CPP

namespace steppers
{
    namespace Nema59Ncm
    {
        enum 
        {
            stepsPerRev = 200,
            stepsPerRevHalfStep = 400,
            quaterStep = 800, 
            eigthStep = 1600,
            sixteenthStep = 3200
        };
    };
};

#endif // STEPPERCONFIGS_CPP