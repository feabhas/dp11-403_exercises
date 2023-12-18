// Longitude.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Longitude_H
#define Longitude_H

#include <iostream>

class Longitude {
public:
  enum class hemi { East, West };
  Longitude() = default;
  explicit Longitude(double lon) : value(lon) {}
  long degrees() const;
  long minutes() const;
  long seconds() const;
  hemi hemisphere() const;

  operator double() const { return value; }

private:
  friend std::ostream &operator<<(std::ostream &os, const Longitude &lon);

  double value{};
};

#endif // Longitude_H
