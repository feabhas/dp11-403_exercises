// Console.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include <iostream>

using namespace std;

Console::Console(GBP initialPertolPrice, GBP initialDiesilPrice,
                 GBP initialLGPPrice)
    : petrolPrice{initialPertolPrice},
      dieselPrice{initialDiesilPrice}, LPGPrice{initialLGPPrice} {}

void Console::updatePetrolPrice(GBP newPrice) {
  petrolPrice = newPrice;
  Subject::notify();
}

void Console::updateDieselPrice(GBP newPrice) {
  dieselPrice = newPrice;
  Subject::notify();
}

void Console::updateLPGPrice(GBP newPrice) {
  LPGPrice = newPrice;
  Subject::notify();
}
