#include "ReVolt.hpp"

void ReVoltMode::enter() {
  motor_l->set_speed(speed_l);
  motor_r->set_speed(speed_r);
}

void ReVoltMode::loop() {
  anticollision_system(); 

  if (Serial.available()) {
    remote_control();
  }
}

void ReVoltMode::anticollision_system() {
  int distance = range->measure();

  //Serial.println(distance);

  if (distance <= 20) {
    float percent = (distance - 10) / 10;

    motor_l->set_speed(speed_l * percent);
    motor_r->set_speed(speed_r * percent);

    return;
  }
  
}

void ReVoltMode::remote_control() {
  char c = Serial.read();
  int speed = Serial.parseInt();

  if (c == 'l') {
    speed_l = speed;
    motor_l->set_speed(speed);
  }

  else if (c == 'r') {
    speed_r = speed;
    motor_r->set_speed(speed);
  }

  else if (c == 'f') {
    speed_r = speed;
    speed_l = speed;
    
    motor_r->set_speed(speed);
    motor_l->set_speed(speed);
  }

  else if (c == 'R') {
    speed_r = speed;
    motor_r->set_speed(speed);
    speed_l = -speed;
    motor_l->set_speed(-speed);
  }

  else if (c == 'L') {
    speed_r = -speed;
    motor_r->set_speed(-speed);
    speed_l = speed;
    motor_l->set_speed(speed);
  }
}
