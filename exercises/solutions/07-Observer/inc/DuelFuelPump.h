// DuelFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DUAL_PUMP_H
#define DUAL_PUMP_H

#include "I_Observer.h"
#include "Litres.h"
#include "GBP.h"

class Console;

class DuelFuelPump : public I_Observer {
public:
  explicit DuelFuelPump(Console &c);
  void buyFuel1(Litres fuel);
  void buyFuel2(Litres fuel);

protected:
  void update() override;

private:
  GBP fuel1Price{1.0_gbp};
  GBP fuel2Price{1.0_gbp};
  Console *console;
};

#endif
