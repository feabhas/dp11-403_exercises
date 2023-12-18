// Latitude.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Latitude.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// ----------------------------------------------------------------------------------------
//
long Latitude::degrees() const { return static_cast<long>(abs(value)); }

long Latitude::minutes() const {
  double currentLatitude = abs(value);

  long lat_deg = static_cast<long>(currentLatitude);
  long lat_min = static_cast<long>((currentLatitude
                - static_cast<double>(lat_deg)) * 60);
  return lat_min;
}

long Latitude::seconds() const {
  double currentLatitude = abs(value);

  long lat_deg = static_cast<long>(currentLatitude);
  long lat_min = static_cast<long>((currentLatitude
                 - static_cast<double>(lat_deg)) * 60);
  long lat_sec = static_cast<long>((currentLatitude
                 - static_cast<double>(lat_deg)
                 - static_cast<double>(lat_min) / 60.0) * 3600);
  return lat_sec;
}

Latitude::hemi Latitude::hemisphere() const {
  return value > 0.0 ? hemi::North : hemi::South;
}

std::ostream &operator<<(std::ostream &os, const Latitude &lat) {
  constexpr auto degreeSymbol =
      "\u00B0"; /// unicode code for Greek letter 'phi'

  os << (lat.hemisphere() == Latitude::hemi::North ? 'N' : 'S') << ' ';
  os << lat.degrees() << degreeSymbol;
  os << lat.minutes() << R"(')";
  os << lat.seconds() << R"(")";

  return os;
}
