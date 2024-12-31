#ifndef NOISE_DETECTOR
#define NOISE_DETECTOR

#include "LM393Detector.hpp"

class NoiseDetector : public LM393Detector {

  public:
    NoiseDetector(int pin): LM393Detector(pin) {}
    bool is_detecting();
};

#endif