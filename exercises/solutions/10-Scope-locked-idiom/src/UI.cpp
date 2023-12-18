// UI.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "UI.h"
#include <iostream>

using std::cout;

UI::UI(Queue &queue) : msgQ{queue} {}

bool UI::run() {
  int selection{};
  cout << "Enter a number (0 to exit): ";
  cin >> selection;
  cout << '\n';

  msgQ.post(selection);

  if (selection == 0)
    return true;
  this_thread::sleep_for(500ms);
  return false; // <=Run again
}
