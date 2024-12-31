#ifndef LM393_DETECTOR
#define LM393_DETECTOR

#include <Arduino.h>

class LM393Detector {
  public:
    const unsigned int MEASUREMENT_DELAY = 100;

  private:
    int pin;
    int last_state;
    unsigned long measurement_time;
    
  public:
    LM393Detector(int out_pin): 
      pin(out_pin), 
      last_state(LOW), 
      measurement_time(0) 
      {}
    
    void setup();

  protected:
    bool measure(int active_on);
};

#endif