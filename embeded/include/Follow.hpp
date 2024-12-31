#ifndef FOLLOW
#define FOLLOW

#include "PlayMode.hpp"
#include "l293d.hpp"
#include "RangeFinder.hpp"

class FollowMode : public PlayMode {
  protected:
    L293D* motor_l;
    L293D* motor_r;
    RangeFinder* range;
    float kp;
    float error;
    float target;

  public:
    FollowMode(L293D* motor_1, L293D* motor_r, RangeFinder* range):
      PlayMode("Follow"),
      motor_l(motor_1), 
      motor_r(motor_r), 
      range(range),
      kp(12.5),
      error(0.0),
      target(12.0)
      {}

    void enter();
    void loop();
};

#endif