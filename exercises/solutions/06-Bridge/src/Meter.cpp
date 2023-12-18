// Meter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Meter.h"
#include "Network.h"
#include <iostream>

using namespace std;

Meter::Meter(I_Network &comms) : network(&comms) { connect(); }

Meter::~Meter() { disconnect(); }

void Meter::connect() { network->openConnection(); }

void Meter::disconnect() { network->closeConnection(); }

void Meter::Tx(const string &str) { network->send(str); }

void Meter::Rx() { network->receive(); }
