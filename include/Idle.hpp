#ifndef IDLE
#define IDLE

#include "PlayMode.hpp"
#include "l293d.hpp"
#include "NoiseDetector.hpp"
#include "TouchDetector.hpp"

class IdleMode : public PlayMode {
  protected:
    L293D* motor_l;
    L293D* motor_r;
    NoiseDetector* noise;
    TouchDetector* touch;

  public:
    IdleMode(L293D* motor_1, L293D* motor_r, NoiseDetector* noise_detector, TouchDetector* touch_detector): 
      PlayMode("Idle"),
      motor_l(motor_1), 
      motor_r(motor_r), 
      noise(noise_detector), 
      touch(touch_detector)
      {}

    void enter();
    void loop();
};

#endif