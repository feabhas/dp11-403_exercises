// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Console.h"
#include "DuelFuelPump.h"
#include "SingleFuelPump.h"

int main()
{
  Console console{1.170_gbp, 1.170_gbp, 1.170_gbp};
  SingleFuelPump pump1{console};
  // DuelFuelPump pump2{console};

  console.attach(pump1);
  // console.attach(pump2);

  console.updatePetrolPrice(1.179_gbp);
  console.updateDieselPrice(1.199_gbp);

  pump1.buyFuel1(10.0_ltrs);

  // pump2.buyFuel1(10.0_ltrs);
  // pump2.buyFuel2(10.0_ltrs);

  console.updatePetrolPrice(1.189_gbp);

  pump1.buyFuel1(10.0_ltrs);

  // pump2.buyFuel1(10.0_ltrs);
  // pump2.buyFuel2(10.0_ltrs);
}
