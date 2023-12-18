// DuelFuelPump.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "DuelFuelPump.h"
#include "Console.h"
#include <iomanip>
#include <iostream>

using namespace std;

void DuelFuelPump::buyFuel1(litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel1Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel1Price << " GBP";
  cout << endl;
}

void DuelFuelPump::buyFuel2(litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel2Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel2Price << " GBP";
  cout << endl;
}
