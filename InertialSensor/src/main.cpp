/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Dec 04 2019                                           */
/*    Description:  This program will turn right 90 degrees using the         */
/*                  Inertial Sensor.                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                       
// LFmotor              motor         1
// LBmotor              motor         10
// RFmotor              motor         11
// RBmotor              motor         19   
// Flywheel1            motor         8               
// Flywheel2            motor         9               
// Indexer              motor         7   
// Inertial Sensor      sensor        20        
// Drivetrain           drivetrain    1, 10, 11, 19      
// ---- END VEXCODE CONFIGURED DEVICES ----

// ----| START CONTROLS INFO |----
// L1 Intake In
// L2 Intake Out
// R1 Indexer
// R2 Flywheel Control
// Tank Drive
// ----| END CONTROLS INFO |----

// Include the V5 Library
#include "vex.h"
// #include "printInertialSensor.h"
  
// Allows for use of the VEX Library
using namespace vex;

// variable for distance of specific leg run
double legDistance = 0;

// variable for turn degree
int turnDegree = 0;

// turn power level
int turnVelocityLevel = 75;

// drive power level
int driveVelocityLevel = 75;

// fwd ref
void inertialPrint();

// factor of 5 --> mulitply distance in inches by a factor of 5 --> i.e. to move 24-in input 120.00 into legDistance variable

int main() 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


  // pseudocode program plan
  // DESCRIPTION: For auton get two rollers
  
  std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;
  std::cout << "Beginning roller auto program movement" << std::endl;
  std::cout << "++++++++++++++++++++++++++++++++++++++" << std::endl;

  // Drives the robot forward for 2-inches
  legDistance = 10.00; 
  std::cout << "2-in fwd movement" << std::endl;
  wait(1000, msec);
  Smartdrive.setDriveVelocity(driveVelocityLevel, velocityUnits::pct);
  Smartdrive.driveFor(directionType::rev, legDistance, distanceUnits::in);
  waitUntil((legDistance >= legDistance));
  Smartdrive.stop(brake);
  std::cout << "2-in fwd movement Complete" << std::endl;
  wait(1000, msec);
  
  // engage intake roller to spin 1st roller

  // Back up robot 5-in
  legDistance = 25.00; 
  std::cout << "back up 5-in movement" << std::endl;
  wait(1000, msec);
  Smartdrive.setDriveVelocity(driveVelocityLevel, velocityUnits::pct);
  Smartdrive.driveFor(directionType::fwd, legDistance, distanceUnits::in);
  waitUntil((legDistance >= legDistance));
  Smartdrive.stop(brake);
  std::cout << "back up 5-in movement Complete" << std::endl;
  wait(1000, msec);

  // turn 270-degrees
  turnDegree = 225; // turn left to 225-degree marker
  Smartdrive.setHeading(0, rotationUnits::deg);
  std::cout << "Beginning 270-degree turn left movement" << std::endl;
  // report new heading out to terminal
  std::cout << "Inertial Sensor's current heading (deg): " << InertialSensor.heading() << std::endl;
  wait(2000, msec);
  // Turns the robot to the right
  Smartdrive.setTurnVelocity(turnVelocityLevel, velocityUnits::pct);
  Smartdrive.turnFor(turnType::left, turnDegree, rotationUnits::deg, false);
  // Waits until the motor reaches turnDegree turn threshold and stops the drivetrain motors
  waitUntil((InertialSensor.rotation(degrees) >= turnDegree));
  Smartdrive.stop(brake);
  std::cout << "225-degree Turn left Movement Complete" << std::endl;
  std::cout << "Inertial Sensor's current heading (deg): " << InertialSensor.heading() << std::endl;
  wait(2000, msec);

  // travel 96-in to other roller
  legDistance = 576.00; // 96-in * 6 = 480
  std::cout << "96-in fwd movement" << std::endl;
  wait(1000, msec);
  Smartdrive.setDriveVelocity(driveVelocityLevel, velocityUnits::pct);
  Smartdrive.driveFor(directionType::rev, legDistance, distanceUnits::in);
  waitUntil((legDistance >= legDistance));
  Smartdrive.stop(brake);
  std::cout << "96-in fwd movement Complete" << std::endl;
  wait(1000, msec);

  // report new heading out to terminal
  std::cout << "Inertial Sensor's current heading (deg): " << InertialSensor.heading() << std::endl;
  wait(1000, msec);
}
