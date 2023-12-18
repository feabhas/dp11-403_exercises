// Console.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

#include "GBP.h"
#include "Subject.h"

class Console : public Subject {
public:
  Console(GBP initialPertolPrice, GBP initialDiesilPrice, GBP initialLGPPrice);
  void updatePetrolPrice(GBP newPrice);
  void updateDieselPrice(GBP newPrice);
  void updateLPGPrice(GBP newPrice);

  GBP currentPetrolPrice() const { return petrolPrice; };
  GBP currentDieselPrice() const { return dieselPrice; };
  GBP currentLPGPrice() const { return LPGPrice; };

private:
  GBP petrolPrice{};
  GBP dieselPrice{};
  GBP LPGPrice{};
};

#endif
