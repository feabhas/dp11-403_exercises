// MBus_Network.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "MBus_Network.h"
#include <iostream>
#include <string_view>

using namespace std;

void MBus::openConnection() { cout << "Opening MBus connection\n"; }

void MBus::closeConnection() { cout << "Closinging MBus connection\n"; }

void MBus::send(string_view str) { cout << "MBus::Send: " << str << '\n'; }

std::string_view MBus::receive() { return "MBus::Receive\n"; }
