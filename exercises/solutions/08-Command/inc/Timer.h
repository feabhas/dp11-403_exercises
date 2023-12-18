// Timer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TIMER_H
#define TIMER_H

class ICommand; // Forward reference

#include <chrono>

class Timer {
public:
  Timer(std::chrono::milliseconds, ICommand &cmd);
  void start();

private:
  void timeout();

  std::chrono::milliseconds tick{};

  friend void connect(Timer &timer, ICommand &cmd);
  ICommand *command{};
};

#endif
