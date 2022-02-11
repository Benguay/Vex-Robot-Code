using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RightWheel;
extern motor LeftWheel;
extern motor BackWheel;
extern motor FrontWheel;
extern controller Controller1;
extern motor_group barLift;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
