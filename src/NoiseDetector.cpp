#include "NoiseDetector.hpp"

bool NoiseDetector::is_detecting() {
  return LM393Detector::measure(LOW);
}