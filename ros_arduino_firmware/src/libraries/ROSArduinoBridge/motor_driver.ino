/***************************************************************
   Motor driver definitions

   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.

   *************************************************************/

#ifdef USE_BASE

#ifdef POLOLU_TB9051FTG
/* Include the Pololu library */
#include <TB9051FTGMotorCarrier.h>

/* Create the motor driver object */
TB9051FTGMotorCarrier leftDrive{LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B};
TB9051FTGMotorCarrier rightDrive{RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B};

/* Wrap the motor driver initialization */
void initMotorController() {
  leftDrive.enable();
  rightDrive.enable();
  
  rightDrive.setBrakeMode(ENABLE_HARD_BRAKE);
  leftDrive.setBrakeMode(ENABLE_HARD_BRAKE);
}

/* Wrap the drive motor set speed function */
void setMotorSpeed(float i, float spd) {
  if (i == LEFT) leftDrive.setOutput(spd);
  else rightDrive.setOutput(spd);
}

// A convenience function for setting both motor speeds
void setMotorSpeeds(float leftSpeed, float rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}

float getMotorCurrent(int i){
  if (i == LEFT) return leftDrive.getCurrent();
  else return rightDrive.getCurrent();
}

// Disable motors
void disableMotors(){
  leftDrive.disable();
  rightDrive.disable();
}

// Disable motors // TODO: Work in progress don't use
void rampDown(){
  int sqrt_ = 0;
  while (leftPID.TargetTicksPerFrame != 0 || rightPID.TargetTicksPerFrame != 0){
    Serial.print("ramp_down: ");
    Serial.println(leftPID.TargetTicksPerFrame);
    if ( leftPID.TargetTicksPerFrame > 0 ){
      sqrt_ = sqrt(leftPID.TargetTicksPerFrame);
      if ( leftPID.TargetTicksPerFrame > sqrt_ ){
        leftPID.TargetTicksPerFrame = leftPID.TargetTicksPerFrame - sqrt_;
      }else{
        leftPID.TargetTicksPerFrame = 0;
      }
    } else {
      if ( leftPID.TargetTicksPerFrame < sqrt_ ){
        leftPID.TargetTicksPerFrame = leftPID.TargetTicksPerFrame + sqrt_;
      }else{
        leftPID.TargetTicksPerFrame = 0;
      }
    }
    
    if ( rightPID.TargetTicksPerFrame > 0 ){
      rightPID.TargetTicksPerFrame = rightPID.TargetTicksPerFrame - 1;
    } else {
      rightPID.TargetTicksPerFrame = rightPID.TargetTicksPerFrame + 1;
    }    

    delay(30);
    updatePID();
    
  }

  setMotorSpeeds(0, 0);
  moving = 0;
}

#else
#error A motor driver must be selected!
#endif

#endif
