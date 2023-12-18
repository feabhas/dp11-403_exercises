// Decorator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Decorator.h"
#include <iostream>

using namespace std;

Decorator::Decorator(I_Waypoint &theObject) : decoratedObject(&theObject) {}

void Decorator::display() const {
  if (decoratedObject)
    decoratedObject->display();
}

void Decorator::decorate(I_Waypoint &theObject)
{
  decoratedObject = &theObject;
}

void decorate(Decorator &dec, I_Waypoint &theObject)
{
  dec.decoratedObject = &theObject;
}
