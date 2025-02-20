// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include <iostream>

using std::cout;

Display::Display(ConcurrentQueue &queue) : msgQ{&queue} {}

bool Display::run() {
  if (msgQ->isEmpty())
    return false;

  auto [value, label] = msgQ->receive();
  cout << "User selected: " << value << '\n';

  if (value == 0)
    return true; // finished
  return false;  // <=Run again
}
