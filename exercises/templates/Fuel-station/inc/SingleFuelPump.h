// SingleFuelPump.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef SINGLE_PUMP_H
#define SINGLE_PUMP_H

using GBP = double;
using litres = double;

class SingleFuelPump {
public:
  SingleFuelPump() = default;
  void buyFuel1(litres fuel);

private:
  GBP fuel1Price{1.0};
};

#endif // SINGLE_PUMP_H
