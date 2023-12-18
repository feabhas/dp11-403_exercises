// Network.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Network.h"
#include "MBus_Network.h"
#include "ZigBee_Network.h"

#include <iostream>
#include <string_view>

using namespace std;

//------------------------------------------------------------------
//
unique_ptr<I_Network> Network_maker::create(Network_maker::NetType type) {
  switch (type) {
  case NetType::Zigbee:
    return make_unique<ZigBee>();
    break;
  case NetType::MBus:
    return make_unique<MBus>();
    break;
  default:
    // return nullptr;
    throw std::invalid_argument("Network type not supported");
  }
}

unique_ptr<I_Network> Network_maker::create(string_view type) {
  if (type == "Zigbee")
    return make_unique<ZigBee>();
  if (type == "MBus")
    return make_unique<MBus>();
  return nullptr;
  throw std::invalid_argument("Network type not supported");
}
