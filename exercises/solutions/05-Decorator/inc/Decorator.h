// Decorator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DECORATORS_H
#define DECORATORS_H

#include "I_Waypoint.h"

class Decorator : public I_Waypoint {
public:
  Decorator() = default;
  explicit Decorator(I_Waypoint &theObject);
  void decorate(I_Waypoint &theObject);
  friend void decorate(Decorator &dec, I_Waypoint &theObject);

protected:
  // I_Displayable interface realisation
  //
  void display() const override = 0;

private:
  I_Waypoint *decoratedObject;
};

#endif // DECORATORS_H
