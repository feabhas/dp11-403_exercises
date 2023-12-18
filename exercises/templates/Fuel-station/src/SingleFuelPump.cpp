// SingleFuelPump.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "SingleFuelPump.h"
#include "Console.h"
#include <iomanip>
#include <iostream>

using namespace std;

void SingleFuelPump::buyFuel1(litres fuel) {
  cout << fixed << setprecision(2);

  cout << "You purchased " << fuel << " litres ";
  cout << "@ " << fuel1Price << " GBP/litre. ";
  cout << "Total cost: " << fuel * fuel1Price << " GBP";
  cout << endl;
}
