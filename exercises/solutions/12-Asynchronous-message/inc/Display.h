// Display.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include "IRunnable.h"
#include "MessageQueue.h"

using value_t = unsigned;
using Queue = MessageQueue<value_t, 16>;

class Display : public IRunnable {
public:
  Display() = default;
  void display(value_t value);

protected:
  bool run() override;

private:
  Queue msgQ{};
};

#endif // DISPLAY_H
