#include "TouchDetector.hpp"

void TouchDetector::setup() {
  if(!accel.begin())
  {
    Serial.println("No valid sensor found");
    while(1);
  }
}

void TouchDetector::detect() {
  accel.getEvent(&event);
}

bool TouchDetector::was_raised() {
  return event.acceleration.z > RAISE_MIN_ACCEL;
}

bool TouchDetector::was_touched() {
  return max(event.acceleration.x, event.acceleration.y) > TOUCH_MIN_ACCEL || min(event.acceleration.x, event.acceleration.y) < -TOUCH_MIN_ACCEL; 
}

char TouchDetector::get_touch_axis() {
  if (max(event.acceleration.x, event.acceleration.y) > TOUCH_MIN_ACCEL) {
    return event.acceleration.x >= event.acceleration.y ? 'x' : 'y';
  } 

  else if (min(event.acceleration.x, event.acceleration.y) < -TOUCH_MIN_ACCEL) {
    return event.acceleration.x <= event.acceleration.y ? '-x' : '-y';
  }

  return ' ';
}

void TouchDetector::debug() {
  Serial.print("x: "); Serial.print(event.acceleration.x);
  Serial.print(", y: "); Serial.print(event.acceleration.y);
  Serial.print(", z: "); Serial.println(event.acceleration.z);
}