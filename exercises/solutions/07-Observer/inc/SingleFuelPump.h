// SingleFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef SINGLE_PUMP_H
#define SINGLE_PUMP_H

#include "I_Observer.h"
#include "Litres.h"
#include "GBP.h"

class Console;

class SingleFuelPump : public I_Observer {
public:
  explicit SingleFuelPump(Console &c);
  void buyFuel1(Litres fuel);

protected:
  void update() override;

private:
  GBP fuel1Price{1.0_gbp};
  Console *console;
};

#endif // SINGLE_PUMP_H
