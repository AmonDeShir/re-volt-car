#ifndef TOUCH_DETECTOR
#define TOUCH_DETECTOR

#include <Arduino.h>
#include "Adafruit_ADXL345_U.h"

class TouchDetector {
  private:
    const float TOUCH_MIN_ACCEL = 2.0;
    const float RAISE_MIN_ACCEL = 13.0;

  protected:
    sensors_event_t event;
    Adafruit_ADXL345_Unified accel;

  public:
    void setup();
    void detect();
    bool was_touched();
    bool was_raised();
    void debug();
    char get_touch_axis();
};

#endif