/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

  
#ifdef ARDUINO_ENC_COUNTER
  #include <Encoder.h>
  
  Encoder leftEnc(LEFT_ENC_PIN_A, LEFT_ENC_PIN_B);
  Encoder rightEnc(RIGHT_ENC_PIN_A, RIGHT_ENC_PIN_B);

  long left_enc_pos = 0L;
  long right_enc_pos = 0L;

  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT){
      left_enc_pos = leftEnc.read();
      return left_enc_pos;
    }else{
      right_enc_pos = rightEnc.read();
      return right_enc_pos;
    }
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos=0L;
      leftEnc.write(0L);
      return;
    } else { 
      right_enc_pos=0L;
      rightEnc.write(0L);
      return;
    }
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif
