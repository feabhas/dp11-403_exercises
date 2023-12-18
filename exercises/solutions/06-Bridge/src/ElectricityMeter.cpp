// ElectricityMeter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ElectricityMeter.h"
#include "Network.h"

#include <iostream>
using namespace std;

Electricity::Electricity(I_Network &comms) : Meter(comms) {}

void Electricity::getReading() {
  cout << "Electricity::getReading" << '\n';
  Tx("DEMAND HIGH RATE READING");
  Rx();
  Tx("DEMAND LOW RATE READING");
  Rx();
}
