// Timer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Timer.h"
#include "ICommand.h"
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

Timer::Timer(std::chrono::milliseconds period, ICommand &cmd)
    : tick{period}, command{&cmd} {}

void Timer::start() {
  constexpr int count{10};
  for (int i = 0; i < count; ++i) // Only do 10 timeouts...
  {
    this_thread::sleep_for(tick);

    cout << "tick...\n";

    // Do some work:
    timeout();
  }
}

// timeout() defines what happens at the end
// of every timer period.
//
void Timer::timeout() { command->execute(); }

void connect(Timer &timer, ICommand &cmd) { timer.command = &cmd; }
