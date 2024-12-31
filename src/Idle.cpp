#include "Idle.hpp"

void IdleMode::enter() {
  motor_l->set_speed(0);
  motor_r->set_speed(0);
}

void IdleMode::loop() {
  touch->detect();
  touch->debug();


  if (touch->was_raised()) {
    motor_l->set_speed(200);
    motor_r->set_speed(200);
    delay(250);
    motor_l->set_speed(-200);
    motor_r->set_speed(-200);
    delay(250);
    motor_l->set_speed(200);
    motor_r->set_speed(200);
    delay(250);
    motor_l->set_speed(0);
    motor_r->set_speed(0);
    delay(1000);
  }

  else if (noise->is_detecting()) {
    for (int i = 0; i < 2; i++) {
      motor_l->set_speed(-200);
      motor_r->set_speed(-200);
      delay(100);
      motor_l->set_speed(200);
      motor_r->set_speed(200);
      delay(100);
    }

    motor_l->set_speed(0);
    motor_r->set_speed(0);
  }

  else if (touch->was_touched()) {
      motor_l->set_speed(150);
      motor_r->set_speed(-150);
      delay(100);
      motor_l->set_speed(-150);
      motor_r->set_speed(150);
      delay(100);
      motor_l->set_speed(0);
      motor_r->set_speed(0);
      delay(500);
  }
}