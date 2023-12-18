// Subject.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Subject.h"
#include "I_Observer.h"

void Subject::attach(I_Observer &obs) { observers.push_back(&obs); }

void Subject::notify() {
  for (auto &obs : observers) {
    obs->update();
  }
}
