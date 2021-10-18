/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER

  #define LEFT_ENC_PIN_A 4  //pin 2
  #define LEFT_ENC_PIN_B 5  //pin 3

  #define RIGHT_ENC_PIN_A 7  //pin 4
  #define RIGHT_ENC_PIN_B 8   //pin 5
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();
