// GBP.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GBP_H
#define GBP_H

#include <iostream>

class GBP {
public:
  GBP() = default;
  constexpr operator double() const { return amt; }

private:
  constexpr explicit GBP(double a) : amt{a} {}
  double amt{};
  friend std::ostream &operator<<(std::ostream &os, const GBP &rhs);
  friend constexpr GBP operator"" _gbp(long double amt);
};

// using long double is characteristic of cooked literal definitions:
// you are forced to use the longest possible type of this “category”:
// for floating-point literals it is long double;
// for integer literals it is unsigned long long.
inline constexpr GBP operator"" _gbp(long double amt) {
  // static_assert( amt > 0, "message");
  return GBP{static_cast<double>(amt)};
}

inline std::ostream &operator<<(std::ostream &os, const GBP &rhs) {
  os << R"(£ )" << rhs.amt;
  return os;
}
#endif // GBP_H
