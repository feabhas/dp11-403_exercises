// ZigBee_Network.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ZigBee_Network.h"
#include <iostream>
#include <string>

using namespace std;

void ZigBee::openConnection() { cout << "Opening ZigBee connection" << '\n'; }

void ZigBee::closeConnection() { cout << "Closing ZigBee connection" << '\n'; }

void ZigBee::send(std::string_view str) {
  cout << "ZigBee::Send: " << str << '\n';
}

void ZigBee::receive() { cout << "ZigBee::Receive" << '\n'; }
