// UI.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef UI_H
#define UI_H

#include "IRunnable.h"
#include "MessageQueue.h"

class UI : public IRunnable {
public:
  explicit UI(MessageQueue &queue);

protected:
  bool run() override;

private:
  MessageQueue *msgQ{};
};

#endif // UI_H
