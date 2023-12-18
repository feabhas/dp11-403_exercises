// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Hardware.h"
#include "Timer.h"

#include <chrono>
#include <iostream>

using namespace std;

int main() {
  cout << "Design Patterns\n";

  [[maybe_unused]] Motor motor{};
  [[maybe_unused]] SevenSeg sevenseg{};
  Timer timer{500ms};

  timer.start();
}
