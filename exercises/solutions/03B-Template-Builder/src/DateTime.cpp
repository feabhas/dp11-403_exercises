// DateTime.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DateTime.h"
#include <chrono>
#include <ctime>

using namespace std;

string DateTime::now() {
  auto now = std::time(nullptr);
  return string{std::asctime(std::localtime(&now))};
}
