#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor RightWheel = motor(PORT2, ratio18_1, true);
motor LeftWheel = motor(PORT5, ratio18_1, false);
motor BackWheel = motor(PORT3, ratio18_1, true);
motor FrontWheel = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
motor barLiftMotorA = motor(PORT6, ratio18_1, false);
motor barLiftMotorB = motor(PORT8, ratio18_1, true);
motor_group barLift = motor_group(barLiftMotorA, barLiftMotorB);
motor barLiftMotor2A = motor(PORT7, ratio18_1, false);
motor barLiftMotor2B = motor(PORT9, ratio18_1, true);
motor_group barLift2 = motor_group(barLiftMotor2A, barLiftMotor2B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
    Brain.Screen.print("Is this working?");

}
