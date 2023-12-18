// AltitudeDecorator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "AltitudeDecorator.h"
#include <iostream>

using namespace std;

AltitudeDecorator::AltitudeDecorator(I_Waypoint &theObject,
                                     unsigned int newAltitude)
    : Decorator{theObject}, altitude{newAltitude} {}

void AltitudeDecorator::display() const {

  // Add any new behaviour.
  //
  cout << "Alt: " << altitude << '\t';

  // Call on the decorated object's functionality
  //
  Decorator::display();
}
