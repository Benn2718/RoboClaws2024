/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       jacob                                                     */
/*    Created:      9/12/2024, 2:42:17 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
motor motor1 = motor(PORT20, ratio18_1, true);
motor motor2 = motor(PORT19, ratio18_1, true);
motor motor3 = motor(PORT18, ratio18_1, true);
motor_group RightSide = motor_group(motor1, motor2, motor3);

motor motor4 = motor(PORT2, ratio18_1, false);
motor motor5 = motor(PORT3, ratio18_1, false);
motor motor6 = motor(PORT1, ratio18_1, false);
motor_group LeftSide = motor_group(motor4, motor5, motor6);

motor motor7 = motor(PORT6, ratio18_1, true);

int run = 100;
void intakeMotor(){
  motor7.spin(directionType::fwd, run, pct);
  
}
void intakeMotorReverse(){
  motor7.spin(directionType::rev, run, pct);
}

void intakeMotorStop(){
  motor7.stop();
}

controller Robo1Controller = controller(primary);
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
  Robo1Controller.ButtonR2.pressed(intakeMotor);
  Robo1Controller.ButtonR2.released(intakeMotorStop);
  Robo1Controller.ButtonR1.pressed(intakeMotorReverse);
  Robo1Controller.ButtonR1.released(intakeMotorStop);
  while (1) {
    int forward = Robo1Controller.Axis3.position();
    int turn = Robo1Controller.Axis1.position();
    

    int leftSpeed = forward + turn;
    int rightSpeed = forward - turn;

    LeftSide.spin(directionType::fwd, leftSpeed,pct);
    RightSide.spin(directionType::fwd, rightSpeed,pct);

    
    

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
