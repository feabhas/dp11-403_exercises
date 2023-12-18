// Console.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include <iostream>

using namespace std;

void Console::updatePetrolPrice(GBP newPrice) {
  petrolPrice = newPrice;

  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}

void Console::updateDieselPrice(GBP newPrice) {
  dieselPrice = newPrice;

  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}

void Console::updateLPGPrice(GBP newPrice) {
  LPGPrice = newPrice;

  // -----------------------------------------------
  // TO DO:
  // Inform any observers that the price has changed.
  //
}
