// Client.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Client.h"
#include "I_Meter.h"

Client::Client(std::initializer_list<I_Meter *> meters) {
  devices.insert(devices.end(), meters.begin(), meters.end());
}

void Client::read() {
  for (auto &device : devices) {
    device->getReading();
  }
}

void connect(Client &c, I_Meter &dev)
{
  c.devices.push_back(&dev);
}
