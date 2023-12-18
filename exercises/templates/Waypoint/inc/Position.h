// Position.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef POSITION_H
#define POSITION_H

#include "Latitude.h"
#include "Longitude.h"

#include <iostream>

class Position {
public:
  Position() = default;
  Position(double lat, double lon);
  void display() const;

private:
  friend std::ostream &operator<<(std::ostream &os, const Position &pos);

  Latitude latitude{};
  Longitude longitude{};
};

#endif // POSITION_H
