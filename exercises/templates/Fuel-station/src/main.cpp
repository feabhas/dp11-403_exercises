// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include "DuelFuelPump.h"
#include "SingleFuelPump.h"

int main()
{
  SingleFuelPump petrol{};
  DuelFuelPump petrolDiesel{};

  petrol.buyFuel1(47.2);
  petrolDiesel.buyFuel1(32.5);
  petrolDiesel.buyFuel2(24.1);
}
