// Longitude.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Longitude.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

long Longitude::degrees() const { return static_cast<long>(abs(value)); }

long Longitude::minutes() const {
  double currentLongitude = abs(value);

  long long_deg = static_cast<long>(currentLongitude);
  long long_min = static_cast<long>((currentLongitude
                 - static_cast<double>(long_deg)) * 60);
  return long_min;
}

long Longitude::seconds() const {
  double currentLongitude = abs(value);

  long long_deg = static_cast<long>(currentLongitude);
  long long_min = static_cast<long>((currentLongitude
                 - static_cast<double>(long_deg)) * 60);
  long long_sec = static_cast<long>((currentLongitude
                 - static_cast<double>(long_deg)
                 - static_cast<double>(long_min) / 60.0) * 3600);
  return long_sec;
}

Longitude::hemi Longitude::hemisphere() const {
  return value > 0.0 ? hemi::East : hemi::West;
}

std::ostream &operator<<(std::ostream &os, const Longitude &lon) {
  // constexpr auto degreeSymbol =
  //   "\u00B0"; /// unicode code for Greek letter 'phi'
  constexpr auto degreeSymbol = R"(°)"; /// raw unicode code

  os << (lon.hemisphere() == Longitude::hemi::East ? 'E' : 'W') << ' ';
  os << lon.degrees() << degreeSymbol;
  os << lon.minutes() << R"(')"; // same as "\'"
  os << lon.seconds() << R"(")"; // same as "\""

  return os;
}
