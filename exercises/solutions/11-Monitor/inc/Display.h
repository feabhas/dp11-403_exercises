// Display.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Display_H
#define Display_H

#include "IRunnable.h"
#include "ConcurrentQueue.h"

class Display : public IRunnable {
public:
  explicit Display(ConcurrentQueue &queue);

protected:
  bool run() override;

private:
  ConcurrentQueue *msgQ{};
};

#endif // Display_H
