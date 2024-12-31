#include <l293d.hpp>
#include <Arduino.h>

void L293D::setup() {
  pinMode(pinDIR1, OUTPUT);
  pinMode(pinDIR2, OUTPUT);

  change_direction();
}

void L293D::change_direction() {
  digitalWrite(pinDIR1, speed > 0 ? HIGH : LOW);
  digitalWrite(pinDIR2, speed > 0 ? LOW : HIGH);
}

void L293D::set_speed(int16_t speed) {
  this->speed = speed;

  uint16_t pwm = abs(speed);
  pwm = min(pwm, maximal_speed);

  if (pwm < minimal_speed) {
    pwm = 0;
  }

  analogWrite(pinPWM, pwm);
  change_direction();
}

int16_t L293D::get_speed() {
  return speed;
}