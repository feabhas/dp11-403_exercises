// DateTime.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DateTime.h"
#include <ctime>
#include <chrono>

std::string DateTime::now() {
  auto now = std::time(nullptr);
  return std::string{std::asctime(std::localtime(&now))};
}
