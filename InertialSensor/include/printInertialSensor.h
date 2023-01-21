#include "vex.h"
using namespace vex;

void inertialPrint( void )
{
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  std::cout <<"**********************************************************************" << std::endl;
  // Prints the pitch ( rotation around the side to side axis)
  Brain.Screen.print("Pitch Orientation (deg): ");
  Brain.Screen.print((InertialSensor.orientation(pitch, degrees)));
  Brain.Screen.newLine();
  std::cout << "Pitch Orientation (deg): " << InertialSensor.orientation(pitch, degrees) << std::endl;

  // Prints the acceleration of the y axis.
  Brain.Screen.print("Y-axis Acceleration (G): ");
  Brain.Screen.print(InertialSensor.acceleration(yaxis));
  Brain.Screen.newLine();
  std::cout << "Y-axis Acceleration (G): " << InertialSensor.acceleration(yaxis) << std::endl;

  // Prints the gyro rate of the y axis
  Brain.Screen.print("Y-axis Gyro Rate (DPS): ");
  Brain.Screen.print(InertialSensor.gyroRate(yaxis, dps));
  Brain.Screen.newLine();
  std::cout << "Y-axis Gyro Rate (DPS): " << InertialSensor.gyroRate(yaxis, dps) << std::endl;

  // Print the current heading in degrees
  Brain.Screen.print("Inertial Sensor's current heading (deg): ");
  Brain.Screen.print(InertialSensor.heading());
  Brain.Screen.newLine();
  std::cout << "Inertial Sensor's current heading (deg): " << InertialSensor.heading() << std::endl;

  // Print the current angle of rotation in degrees
  Brain.Screen.print("Inertial Sensor's current angle of rotation (deg): ");
  Brain.Screen.print(InertialSensor.rotation());
  wait(0.2, seconds);
  std::cout << "Inertial Sensor's current angle of rotation (deg): " << InertialSensor.rotation() << std::endl;
  std::cout <<"**********************************************************************" << std::endl;
}