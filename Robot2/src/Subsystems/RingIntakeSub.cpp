#include "RingIntakeSub.h"

void RingIntakeSub::intakeRing(double speed)
{
    ringIntakeMotor.spin(forward, speed, rpm);
}