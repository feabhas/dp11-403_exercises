// ZigBee_Network.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ZIGBEE_NETWORK_H
#define ZIGBEE_NETWORK_H

#include "Network.h"

class ZigBee : public I_Network {
// protected:
public:
  void openConnection() override;
  void closeConnection() override;
  void send(std::string_view str) override;
  std::string_view receive() override;
};

#endif // ZIGBEE_NETWORK_H
