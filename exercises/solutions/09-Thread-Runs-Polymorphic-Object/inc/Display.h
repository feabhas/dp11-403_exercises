// Display.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Display_H
#define Display_H

#include "IRunnable.h"
#include "MessageQueue.h"

class Display : public IRunnable {
public:
  explicit Display(Queue &queue);

protected:
  bool run() override;

private:
  Queue *msgQ{};
};

#endif // Display_H
