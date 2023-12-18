// Behaviour.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Behaviour.h"

#include "Hardware.h"

void MotorBehaviour::execute() {
  if (isOn) {
    context.off();
  } else {
    context.on();
  }
  isOn = not isOn;
}
