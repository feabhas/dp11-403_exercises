// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "MBus_Network.h"
#include "Network.h"
#include "ZigBee_Network.h"

#include <iostream>

int main() {
  std::cout << "Design Patterns\n";

  try {

    std::unique_ptr<I_Network> pNetwork{};
    // decltype(Network_maker::create("")) pNetwork{};

    if (pNetwork = Network_maker::create("Zigbee"); not pNetwork) {
      throw std::invalid_argument("Zigbee not supported");
    }
    pNetwork->send("Hello world");

    if (auto new_nw = Network_maker::create(Network_maker::NetType::MBus)) {
      pNetwork = std::move(new_nw); // only replace link if successful
    }
    pNetwork->send("Hello world");

    if (auto new_nw = Network_maker::create("Ethernet")) {
      pNetwork = std::move(new_nw);
    }
    pNetwork->send("Hello world");

  } catch (std::invalid_argument &ex) {
    std::cout << ex.what() << '\n';
  } catch (std::bad_alloc &ex) {
    std::cout << "Run out of memory!" << '\n';
  }

  //
  // Using Template factory function
  //
  {
    auto zigbee = make_network<ZigBee>();
    zigbee.openConnection();
    zigbee.send("message sent");
    zigbee.closeConnection();
  }
}
