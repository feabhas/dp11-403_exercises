// Console.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef CONSOLE_H
#define CONSOLE_H

using GBP = double;

class Console {
public:
  Console() = default;
  void updatePetrolPrice(GBP newPrice);
  void updateDieselPrice(GBP newPrice);
  void updateLPGPrice(GBP newPrice);

private:
  GBP petrolPrice{};
  GBP dieselPrice{};
  GBP LPGPrice{};
};

#endif
