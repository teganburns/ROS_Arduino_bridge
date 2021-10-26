/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER

  #define LEFT_ENC_PIN_A 4  //pin 4
  #define LEFT_ENC_PIN_B 5  //pin 5

  #define RIGHT_ENC_PIN_A 7  //pin 7
  #define RIGHT_ENC_PIN_B 8   //pin 8
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
