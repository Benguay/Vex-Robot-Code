/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\benan                                            */
/*    Created:      Tue Dec 07 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RightWheel           motor         2               
// LeftWheel            motor         5               
// BackWheel            motor         3               
// FrontWheel           motor         4               
// Controller1          controller                    
// barLift              motor_group   6, 7            
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"


using namespace vex;
competition Competition;


int forBackVal  = 0;
int strafeVal   = 0;
int rotationVal = 0;

int C1LX = 0;
int C1LY = 0;
int C1RX = 0;

bool normal = true;


void omniDriveCode() {
  forBackVal   =  Controller1.Axis3.position();
  strafeVal    =  Controller1.Axis4.position();
  rotationVal  =  Controller1.Axis1.position();

  //Maths
  if((Controller1.Axis3.position() >= 50 && Controller1.Axis4.position() >= 50) || (Controller1.Axis3.position() <= -50 && Controller1.Axis4.position() <= -50)){
    //forward right diag
    Brain.Screen.print("Forward Right Diag");
    LeftWheel.setVelocity(forBackVal, percent);
    FrontWheel.setVelocity(forBackVal, percent);
    RightWheel.setVelocity(forBackVal, percent);
    BackWheel.setVelocity(forBackVal, percent);
  } /*else if((Controller1.Axis3.position() >= 50 && Controller1.Axis4.position() <= -50) || (Controller1.Axis3.position() <= -50 && Controller1.Axis4.position() >= 50)){
    //forward left diag
    Brain.Screen.print("Forward Left Diag");
    LeftWheel.setVelocity(forBackVal, percent);
    FrontWheel.setVelocity(-forBackVal, percent);
    RightWheel.setVelocity(forBackVal, percent);
    BackWheel.setVelocity(-forBackVal, percent);
  }*/ else {
    FrontWheel.setVelocity(strafeVal+rotationVal, percent);
    BackWheel.setVelocity(strafeVal-rotationVal, percent);
    RightWheel.setVelocity(forBackVal-rotationVal, percent);
    LeftWheel.setVelocity((forBackVal+rotationVal), percent);
  }
}

void speedDemon() {
  C1LX = -Controller1.Axis1.position();
  //C1LY =  Controller1.Axis1.position();
  C1RX = -Controller1.Axis3.position();

  LeftWheel.setVelocity(-C1LY - C1LX - C1RX, percent);
	FrontWheel.setVelocity( C1LY - C1LX - C1RX, percent);
	RightWheel.setVelocity( C1LY + C1LX - C1RX, percent);
	BackWheel.setVelocity(-C1LY + C1LX - C1RX, percent);
}


void barLiftCode(){
  if(Controller1.ButtonR1.pressing()){
    barLift.setVelocity(500, rpm);
  } else if (Controller1.ButtonR2.pressing()) {
    barLift.setVelocity(-500, rpm);
  } /*else if (Controller1.ButtonL1.pressing()) {
    barLift.setVelocity(56,rpm);
  } else if (Controller1.ButtonL2.pressing()) {
    barLift.setVelocity(-56, rpm); 
  } */else {
    barLift.setVelocity(0, rpm);
  }
  barLift.spin(forward);
}

void boolFlipper() {
//  if(Controller1.ButtonL1.pressing()){
    normal = !normal;
    wait(100, msec);
//  }
}

void rightA(int ms, bool no = 0, int speed = 500) {
  FrontWheel.setVelocity(speed, rpm);
  BackWheel.setVelocity(speed, rpm);
  FrontWheel.spin(forward);
  BackWheel.spin(forward);
  wait(ms, msec);

  if(no == 0){
    FrontWheel.setVelocity(0, rpm);
    BackWheel.setVelocity(0, rpm);
    FrontWheel.spin(forward);
    BackWheel.spin(forward);
  }
}

void leftA(int ms, bool no = 0, int speed = 500) {
  FrontWheel.setVelocity(-speed, rpm);
  BackWheel.setVelocity(-speed, rpm);
  FrontWheel.spin(forward);
  BackWheel.spin(forward);
  wait(ms, msec);

  if(no == 0){
    FrontWheel.setVelocity(0, rpm);
    BackWheel.setVelocity(0, rpm);
    FrontWheel.spin(forward);
    BackWheel.spin(forward);
  }
}

void forwardA(int ms, bool no = 0, int speed = 500) {
  RightWheel.setVelocity(speed, rpm);
  LeftWheel.setVelocity(speed, rpm);
  RightWheel.spin(forward);
  LeftWheel.spin(forward);
  wait(ms, msec);
  
  if(no == 0){
    RightWheel.setVelocity(0, rpm);
    LeftWheel.setVelocity(0, rpm);
    RightWheel.spin(forward);
    LeftWheel.spin(forward);
  }
}

void backwardA(int ms, bool no = 0, int speed = 500) {
  RightWheel.setVelocity(-speed, rpm);
  LeftWheel.setVelocity(-speed, rpm);
  RightWheel.spin(forward);
  LeftWheel.spin(forward);
  wait(ms, msec);

  if(no == 0) {
    RightWheel.setVelocity(0, rpm);
    LeftWheel.setVelocity(0, rpm);
    RightWheel.spin(forward);
    LeftWheel.spin(forward);
  }
}

void rotateA(int ms, bool directio, int speed = 500) {
  
  FrontWheel.setVelocity(speed, rpm);
  BackWheel.setVelocity(-speed, rpm);
  RightWheel.setVelocity(-speed, rpm);
  LeftWheel.setVelocity((speed), rpm);
  if(directio == 1) {
    //Right CW (Probably)
    FrontWheel.spin(forward);
    BackWheel.spin(forward);
    RightWheel.spin(forward);
    LeftWheel.spin(forward);
  } else {
    //Left CCW (Probably)
    FrontWheel.spin(reverse);
    BackWheel.spin(reverse);
    RightWheel.spin(reverse);
    LeftWheel.spin(reverse);
  }
  wait(ms, msec);

  FrontWheel.setVelocity(0, rpm);
  BackWheel.setVelocity(0, rpm);
  RightWheel.setVelocity(0, rpm);
  LeftWheel.setVelocity(0, rpm);

  FrontWheel.spin(forward);
  BackWheel.spin(forward);
  RightWheel.spin(forward);
  LeftWheel.spin(forward);
}

void fourBarA(int ms, bool dir) {
  if(dir==1){
    barLift.setVelocity(500, rpm);
  } else {
    barLift.setVelocity(-500,rpm);
  }

  barLift.spin(forward);
  wait(ms, msec);

  barLift.setVelocity(0, rpm);
  barLift.spin(forward);
}

void freezeA(){
  FrontWheel.setVelocity(0, rpm);
  BackWheel.setVelocity(0, rpm);
  RightWheel.setVelocity(0, rpm);
  LeftWheel.setVelocity(0, rpm);
  barLift.setVelocity(0, rpm);

  FrontWheel.spin(forward);
  BackWheel.spin(forward);
  RightWheel.spin(forward);
  LeftWheel.spin(forward);
  barLift.spin(forward);
}

void toss(){
  if(Controller1.ButtonL1.pressing()){
    forwardA(500, 1);
    fourBarA(200, 0);
    freezeA();
  }
}

void autonomousCode(){
  forwardA(0, 1);
  fourBarA(1000, 0); //up
  wait(2000, msec);
  freezeA();

  fourBarA(1, 2000);
  backwardA(3000);
}

void userControl(void){

  while(1==1) {
      Controller1.ButtonDown.pressed(boolFlipper);

      if(normal){
        omniDriveCode();
      } else {
        speedDemon();
      }
      barLiftCode();
      toss();
      BackWheel.spin  (forward);
      FrontWheel.spin (forward);
      LeftWheel.spin  (forward);
      RightWheel.spin (forward);
      wait(10, msec);
  }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  Competition.autonomous(autonomousCode);
  Competition.drivercontrol(userControl);

  // Run the pre-autonomous function.
  vexcodeInit();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
