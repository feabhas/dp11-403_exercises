// Position.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Position.h"

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Position::Position(double lat, double lon) : latitude(lat), longitude(lon) {
  // cout << "Position ctor" << '\n';
}

void Position::display() const { cout << *this; }

std::ostream &operator<<(std::ostream &os, const Position &pos) {
  os << pos.latitude;
  os << "\t";
  os << pos.longitude;

  return os;
}
