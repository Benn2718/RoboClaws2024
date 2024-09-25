#include "vex.h"
#include "Constants.h"

using namespace vex;

#ifndef RINGINTAKESUB_H
#define RINGINTAKESUB_H

class RingIntakeSub
{
    private:
        motor ringIntakeMotor = motor(kRingIntakeMotorIndex, kRingIntakeMotorInverted);

    public:
        /**
         * Spins the ring intake motor
         * @param speed the speed to spin the intake motor to (+)foward (-)backward
         */
        void intakeRing(double speed);
};

#endif