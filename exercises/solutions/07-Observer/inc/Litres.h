// Litres.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef LITRES_H
#define LITRES_H

#include <iostream>

class Litres {
public:
  Litres() = default;
  operator double() const { return amt; }

private:
  constexpr explicit Litres(double a) : amt{a} {}
  double amt{};
  friend std::ostream &operator<<(std::ostream &os, const Litres &rhs);
  friend constexpr Litres operator"" _ltrs(long double amt);
};

inline constexpr Litres operator"" _ltrs(long double amt) {
  return Litres{static_cast<double>(amt)};
}

inline std::ostream &operator<<(std::ostream &os, const Litres &rhs) {
  os << rhs.amt;
  return os;
}

#endif // LITRES_H
