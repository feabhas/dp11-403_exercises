// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"

#include <iostream>
using namespace std;

void Display::display(value_t value) { msgQ.post(value); }

bool Display::run() {
  unsigned userChoice = msgQ.get();
  cout << "User selected: " << userChoice << '\n';
  cout.flush();

  if (userChoice != 0)
    return false; // Run again
  else
    return true; // finished
}
