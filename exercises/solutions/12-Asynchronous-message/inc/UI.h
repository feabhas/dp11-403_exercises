// UI.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef UI_H
#define UI_H

#include "IRunnable.h"

class Display;

class UI : public IRunnable {
public:
  explicit UI(Display &display);

protected:
  bool run() override;

private:
  Display *pDisplay{};
};

#endif // UI_H
