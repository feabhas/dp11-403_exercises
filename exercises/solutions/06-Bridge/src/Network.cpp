// Network.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Network.h"
#include "MBus_Network.h"
#include "ZigBee_Network.h"

#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------------
//
shared_ptr<I_Network> Network::create(Network::NetType type) {
  shared_ptr<I_Network> network{};
  switch (type) {
  case NetType::Zigbee:
    network = make_shared<ZigBee>();
    break;
  case NetType::MBus:
    network = make_shared<MBus>();
    break;
  default:
    throw std::invalid_argument("Network type not supported");
  }
  return network;
}
