#include "vex.h"
#include "Constants.h"

using namespace vex;

#ifndef DRIVESUB_H
#define DRIVESUB_H

class DriveSub
{
    private:
        //All motors for the Drivetrain/subsystem
        motor lDriveMotor1 = motor(kL1DriveMotorIndex, kL1DriveMotorInverted);
        motor lDriveMotor2 = motor(kL2DriveMotorIndex, kL2DriveMotorInverted);
        motor rDriveMotor1 = motor(kR1DriveMotorIndex, kR1DriveMotorInverted);
        motor rDriveMotor2 = motor(kR2DriveMotorIndex, kR2DriveMotorInverted);

        //Grouping the left and right motors
        motor_group lDriveGroup = motor_group(lDriveMotor1, lDriveMotor2);
        motor_group rDriveGroup = motor_group(rDriveMotor1, rDriveMotor2);
    
    public:
        /**
         * Move the robot foward and backward and turn using mechanum
         * @param Yspeed The direction (-)backward, (+)foward and the speed, abs(inputed value) 
         * @param RotSpeed The speed and direction, (-)left (+)right of the rotation of the robot
         * @param StrafeSpeed The speed, (-)left (+)right, for the strafe, left and right
         */
        void drive(double Yspeed, double Rotspeed, double StrafeSpeed);
};

#endif