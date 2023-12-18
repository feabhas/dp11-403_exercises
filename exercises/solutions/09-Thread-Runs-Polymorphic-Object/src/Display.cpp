// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include <iostream>

using std::cout;

Display::Display(Queue &queue) : msgQ{&queue} {}

bool Display::run() {
  if (msgQ->isEmpty())
    return false;

  int userChoice = msgQ->get();
  cout << "User selected: " << userChoice << '\n';

  if (userChoice == 0)
    return true; // finished
  return false;  // <=Run again
}
