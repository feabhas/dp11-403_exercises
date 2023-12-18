// UI.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "UI.h"
#include "Display.h"
#include <iostream>

using std::cout;

// -------------------------------------------------------------
//
UI::UI(Display &display) : pDisplay{&display} {}

bool UI::run() {
  unsigned selection{};
  cout << "Enter a number (0 to exit): ";
  cout.flush();
  cin >> selection;

  pDisplay->display(selection);
  this_thread::sleep_for(10ms);

  if (selection != 0)
    return false; // <=Run again
  else
    return true; // finished
}
