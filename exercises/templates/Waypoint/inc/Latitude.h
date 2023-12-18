// Latitude.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Latitude_H
#define Latitude_H

#include <iostream>

class Latitude {
public:
  enum class hemi { North, South };
  Latitude() = default;
  explicit Latitude(double lat) : value(lat) {}
  long degrees() const;
  long minutes() const;
  long seconds() const;
  hemi hemisphere() const;

  operator double() const { return value; }

private:
  friend std::ostream &operator<<(std::ostream &os, const Latitude &lat);

  double value{};
};

#endif // POSITION_H
