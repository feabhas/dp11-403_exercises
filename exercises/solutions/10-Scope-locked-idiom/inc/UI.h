// UI.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef UI_H
#define UI_H

#include "IRunnable.h"
#include "ConcurrentQueue.h"

class UI : public IRunnable {
public:
  explicit UI(ConcurrentQueue &queue);

protected:
  bool run() override;

private:
  ConcurrentQueue *msgQ{};
};

#endif // UI_H
