// Timer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Timer.h"
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

Timer::Timer(std::chrono::milliseconds period) : tick{period} {}

void Timer::start() {
  constexpr int num_of_ticks = 10; // Only do 10 timeouts...
  for (int i = 0; i < num_of_ticks; ++i) {
    this_thread::sleep_for(tick);

    cout << "...tick...\n";

    // Do some work:
    timeout();
  }
}

// timeout() defines what happens at the end
// of every timer period.
//
void Timer::timeout() {
  // TO DO:
}
