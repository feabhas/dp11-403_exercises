// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "ZigBee_Network.h"
#include "MBus_Network.h"

#include <iostream>

int main()
{
  std::cout << "Design Patterns\n";

  ZigBee comms{};

  I_Network* ptr = &comms;

  ptr->openConnection();
  ptr->send("message");
  ptr->receive();
  ptr->closeConnection();
}
