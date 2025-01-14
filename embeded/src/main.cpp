#include <Arduino.h>
#include <Wire.h>
#include "l293d.hpp"
#include "NoiseDetector.hpp"
#include "RangeFinder.hpp"
#include "TouchDetector.hpp"
#include "PlayMode.hpp"
#include "PCF8574.h"
#include "ReVolt.hpp"
#include "Idle.hpp"
#include "Follow.hpp"

PCF8574 expander(0b0100111);
L293D engineL(10, 9, 8);
L293D engineR(6, 5, 4);
NoiseDetector noise(7);
RangeFinder rangefinder(11, 12);
TouchDetector touch_detector;

volatile int mode = 0;
volatile unsigned long next_mode_change = 0;

const int mode_size = 3;
const int mode_leds[mode_size] = { 5, 6, 7 };

void update_leds();
void change_mode();


PlayMode* playmodes[mode_size] = {
  new IdleMode(&engineL, &engineR, &noise, &touch_detector),
  new ReVoltMode(&engineL, &engineR, &rangefinder),
  new FollowMode(&engineL, &engineR, &rangefinder),
};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  expander.begin();

  engineL.setup();
  engineR.setup();
  noise.setup();
  rangefinder.setup();
  touch_detector.setup();

  for (int i = 0; i < mode_size; i++) {
    expander.write(mode_leds[i], HIGH); 
  }

  playmodes[mode]->enter();
  update_leds();


  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), change_mode, FALLING);
}

void change_mode() {
  noInterrupts();

  if (next_mode_change > millis()) {
    return;  
  }

  next_mode_change = millis() + 250;
  interrupts();


  playmodes[mode]->exit();
  
  mode += 1;

  if (mode >= mode_size) {
    mode = 0;
  }

  update_leds();

  playmodes[mode]->enter();
}

void update_leds() {
  for (int i = 0; i < mode_size; i++) {
    expander.write(mode_leds[i], HIGH); 
  }

  expander.write(mode_leds[mode], LOW); 
}

void loop() {  
  playmodes[mode]->loop();
}