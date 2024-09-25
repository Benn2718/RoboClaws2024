#include "DriveSub.h"

void DriveSub::drive(double Yspeed, double Rotspeed, double StrafeSpeed)
{
    double LeftFrontWheelSpeed = Yspeed + StrafeSpeed - Rotspeed;
    double RightFrontWheelSpeed = Yspeed - StrafeSpeed - Rotspeed;
    double LeftBackWheelSpeed = Yspeed - StrafeSpeed + Rotspeed;
    double RightBackWheelSpeed = Yspeed + StrafeSpeed - Rotspeed;

    rDriveMotor1.spin(forward, RightFrontWheelSpeed, rpm);
    rDriveMotor2.spin(forward, RightBackWheelSpeed, rpm);

    lDriveMotor1.spin(forward, LeftFrontWheelSpeed, rpm);
    lDriveMotor2.spin(forward, LeftBackWheelSpeed, rpm);
}