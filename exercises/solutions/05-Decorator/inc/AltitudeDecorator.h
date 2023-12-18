// AltitudeDecorator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALTITUDE_DECORATORS_H
#define ALTITUDE_DECORATORS_H

#include "I_Waypoint.h"

#include "Decorator.h"

class AltitudeDecorator : public Decorator {
public:
  AltitudeDecorator(I_Waypoint &theObject, unsigned int newAltitude);

protected:
  // I_Displayable interface realisation
  //
  void display() const override;

private:
  unsigned int altitude{};
};

#endif // ALTITUDE_DECORATORS_H
