// WaterMeter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "WaterMeter.h"
#include "Network.h"

#include <iostream>
using namespace std;

Water::Water(I_Network &comms) : Meter(comms) {}

void Water::getReading() {
  cout << "Water::getReading" << '\n';
  Tx("DEMAND WATER READING");
  Rx();
}
