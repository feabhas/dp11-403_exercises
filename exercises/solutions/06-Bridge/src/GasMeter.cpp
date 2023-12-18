// GasMeter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "GasMeter.h"
#include "Network.h"

#include <iostream>
using namespace std;

Gas::Gas(I_Network &comms) : Meter(comms) {}

void Gas::getReading() {
  cout << "Gas::getReading" << '\n';
  Tx("DEMAND GAS READING");
  Rx();
}
