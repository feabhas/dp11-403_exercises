// Timer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
  Timer(std::chrono::milliseconds period);
  void start();

private:
  void timeout();
  std::chrono::milliseconds tick{};
};

#endif
