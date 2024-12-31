#ifndef RANGE_FINDER
#define RANGE_FINDER

#include <Arduino.h>

class RangeFinder {
  private:
    const int ECHO_UPTIME_TO_CM = 58;
    int echo;
    int trigger;
    int last_measurement;

  public:
    RangeFinder(int echo_pin, int trigger_pin): 
      echo(echo_pin), 
      trigger(trigger_pin), 
      last_measurement(0) 
      {}
    
    void setup();
    int measure();
    int get_last_measurement();
};

#endif