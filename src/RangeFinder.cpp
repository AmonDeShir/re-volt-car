#include <Arduino.h>
#include "RangeFinder.hpp"

void RangeFinder::setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT); 
}

int RangeFinder::measure() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  last_measurement = pulseIn(echo, HIGH) / ECHO_UPTIME_TO_CM;
  return last_measurement;
}

int RangeFinder::get_last_measurement() {
  return last_measurement;
}