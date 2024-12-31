#include "Follow.hpp"

void FollowMode::enter() {
  motor_l->set_speed(0);
  motor_r->set_speed(0);
}

void FollowMode::loop() {
  float measure = range->measure() + 3;
  
  if (measure >= 50) {
    motor_l->set_speed(150);
    motor_r->set_speed(0);
    Serial.print("mm: "); Serial.print(measure);

    return;
  }

  float error = measure - (target + 3);

  Serial.print("m: "); Serial.print(measure);
  Serial.print(", t: "); Serial.print(target);
  Serial.print(", e: "); Serial.print(error);
  Serial.print(", p: "); Serial.print(kp);
  Serial.print(", r: "); Serial.println(error * kp);

  motor_l->set_speed(error * kp);
  motor_r->set_speed(error * kp);
}