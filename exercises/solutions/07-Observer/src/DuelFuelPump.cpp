// DuelFuelPump.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DuelFuelPump.h"
#include "Console.h"
#include <iomanip>
#include <iostream>

using namespace std;

DuelFuelPump::DuelFuelPump(Console &c) : console{&c} {
  fuel1Price = console->currentPetrolPrice();
  fuel2Price = console->currentDieselPrice();
}


void DuelFuelPump::buyFuel1(Litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel1Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel1Price << " GBP";
  cout << '\n';
}

void DuelFuelPump::buyFuel2(Litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel2Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel2Price << " GBP";
  cout << '\n';
}
void DuelFuelPump::update() {
  fuel1Price = console->currentPetrolPrice();
  fuel2Price = console->currentDieselPrice();
}
