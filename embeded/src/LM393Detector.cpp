#include <Arduino.h>
#include "LM393Detector.hpp"

void LM393Detector::setup() {
  pinMode(pin, INPUT);
}

bool LM393Detector::measure(int activate_on) {
  int state = digitalRead(pin);
  
  if (last_state != state && state == activate_on) {
    if (millis() - measurement_time > MEASUREMENT_DELAY) {
      measurement_time = millis();
      last_state = state;
      
      return true;
    }
  }

  last_state = state;
  return false;
}