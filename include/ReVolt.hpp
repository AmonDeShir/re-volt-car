#ifndef REVOLT
#define REVOLT

#include "PlayMode.hpp"
#include "l293d.hpp"
#include "RangeFinder.hpp"

class ReVoltMode : public PlayMode {
  protected:
    L293D* motor_l;
    L293D* motor_r;
    RangeFinder* range;    
    int speed_l;
    int speed_r;

  public:
    ReVoltMode(L293D* motor_1, L293D* motor_r, RangeFinder* range_finder): 
      PlayMode("ReVolt"),
      motor_l(motor_1),
      motor_r(motor_r), 
      range(range_finder), 
      speed_l(0), 
      speed_r(0) 
      {}

    void enter();
    void loop();

  protected:
    void anticollision_system();
    void remote_control();
    
};

#endif