#include "Follow.hpp"

void FollowMode::enter() {
  motor_l->set_speed(0);
  motor_r->set_speed(0);
}

void FollowMode::loop() {
  float measure = range->measure() + 3;
  
  if (measure >= 50) {
    motor_l->set_speed(0);
    motor_r->set_speed(0);

    return;
  }

  float error = measure - (target + 3);

  motor_l->set_speed(error * kp);
  motor_r->set_speed(error * kp);
}