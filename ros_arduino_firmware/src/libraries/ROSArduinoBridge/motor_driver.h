/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef POLOLU_TB9051FTG

  // PWM output pins
  #define LEFT_MOTOR_PIN_A 0
  #define LEFT_MOTOR_PIN_B 1
  #define RIGHT_MOTOR_PIN_A 2
  #define RIGHT_MOTOR_PIN_B 3

  // Hard brake (1) or rolling brake (0)
  #define ENABLE_HARD_BRAKE 0

  // Used for motor current measurments
  #define LEFT_MOTOR_OCM_PIN A0
  #define RIGHT_MOTOR_OCM_PIN A1

#endif

void initMotorController();
void setMotorSpeed(float i, float spd);
void setMotorSpeeds(float leftSpeed, float rightSpeed);
float getMotorCurrent(int i);
void diableMotors();

//rate in ms. The higher the rate the slower it ramps down
void rampDown();
