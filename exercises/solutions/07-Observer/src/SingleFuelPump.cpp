// SingleFuelPump.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "SingleFuelPump.h"
#include "Console.h"
#include <iomanip>
#include <iostream>

using namespace std;

SingleFuelPump::SingleFuelPump(Console &c):console{&c}{
  fuel1Price = console->currentPetrolPrice();
}

void SingleFuelPump::buyFuel1(Litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel1Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel1Price << " GBP";
  cout << '\n';
}

void SingleFuelPump::update() {
  fuel1Price = console->currentPetrolPrice();
}
