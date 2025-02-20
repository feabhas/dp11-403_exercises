// UI.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "UI.h"
#include <iostream>

UI::UI(ConcurrentQueue &queue) : msgQ{&queue} {}

constexpr int max_value = 10U;

bool UI::run() {
  int selection{};
  std::cout << "Enter a number (0 to exit): ";
  std::cin >> selection;
  std::cout << '\n';

  selection %= max_value;
  msgQ->send(selection);
  if (selection == 0)
    return true;
  return false; // <=Run again
}
