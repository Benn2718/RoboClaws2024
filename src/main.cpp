/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jacob                                                     */
/*    Created:      9/3/2024, 3:25:46 PM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
brain robo2_Brain;

motor frontLeft = motor(PORT11, ratio6_1, true);
motor backLeft = motor(PORT20, ratio6_1, true);
motor_group LeftDrive = motor_group(frontLeft, backLeft);

motor frontRight =  motor(PORT1, ratio6_1, false);
motor backRight = motor(PORT10, ratio6_1, false);
motor_group RightDrive = motor_group(frontRight,backRight);

digital_out clawGrab = digital_out(robo2_Brain.ThreeWirePort.A);

//Adjusting for new gear ratio
double adjustedPower(double originalPower){
  return originalPower * (48.0/72.0);
}

controller Controller1 = controller(primary);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
    //Gets speed from pushing the left and right joysticks forward or backwards.
    int forwardSpeed = Controller1.Axis3.position();

    //Gets turn values from right joystick
    int turnSpeed = Controller1.Axis1.position();

    /**Get values for strafing side-to-side
    int strafe = Controller1.Axis4.position();
    **/

    //Turns the robot
    int leftSpeed = forwardSpeed + turnSpeed;
    int rightSpeed = forwardSpeed - turnSpeed;
    
    //Motors will spin in the direction of the joysticks
    LeftDrive.spin(forward, adjustedPower(leftSpeed), percent);
    RightDrive.spin(forward, adjustedPower(rightSpeed), percent);

    /**Mecanum Wheel strafe code
    frontRight.spin(directionType::fwd, forwardSpeed - strafe + turnSpeed, velocityUnits:: pct);
    frontLeft.spin(directionType::fwd, forwardSpeed + strafe - turnSpeed, velocityUnits::pct);
    backRight.spin(directionType::fwd, forwardSpeed + strafe + turnSpeed, velocityUnits::pct);
    backLeft.spin(directionType::fwd, forwardSpeed - strafe - turnSpeed, velocityUnits::pct);
    **/
   

   //Pneumatic code: Press A to activte claw to grab.
static bool isClawOpen = false;
if (Controller1.ButtonA.pressing()){
  isClawOpen = !isClawOpen;
  clawGrab.set(isClawOpen);
  wait(500,msec);
}

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}

