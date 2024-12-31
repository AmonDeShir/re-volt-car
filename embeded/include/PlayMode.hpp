#ifndef PLAYMODE
#define PLAYMODE
#include "Arduino.h"

class PlayMode {
  protected:
    String name;

  public:
    PlayMode (String name): name(name) {};

    inline virtual void enter() {
      Serial.println("Active mode -> " + name);
    }

    virtual void loop() {}
    inline void exit() {}
};

#endif