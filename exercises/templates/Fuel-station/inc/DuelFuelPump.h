// DuelFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef DUAL_PUMP_H
#define DUAL_PUMP_H

using GBP = double;
using litres = double;

class DuelFuelPump {
public:
  DuelFuelPump() = default;
  void buyFuel1(litres fuel);
  void buyFuel2(litres fuel);

private:
  GBP fuel1Price{1.0};
  GBP fuel2Price{1.0};
};

#endif
