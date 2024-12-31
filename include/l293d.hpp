#ifndef ENGINE
#define ENGINE
#include <Arduino.h>

class L293D {
protected:
  uint16_t minimal_speed;
  uint16_t maximal_speed;
  uint8_t pinPWM;
  uint8_t pinDIR1;
  uint8_t pinDIR2;
  int16_t speed;

public:
  L293D (uint8_t pwm, uint8_t dir1, uint8_t dir2): 
    pinPWM(pwm), 
    pinDIR1(dir1), 
    pinDIR2(dir2), 
    speed(0),
    minimal_speed(100),
    maximal_speed(255)
    {};

  void setup();
  void set_speed(int16_t speed);
  int16_t get_speed();

protected:
  void change_direction();
};

#endif