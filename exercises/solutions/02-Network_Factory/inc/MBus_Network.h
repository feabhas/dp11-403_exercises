// MBus_Network.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MBUS_NETWORK_H
#define MBUS_NETWORK_H

#include "Network.h"

class MBus : public I_Network {
public:
  void openConnection() override;
  void closeConnection() override;
  void send(std::string_view str) override;
  std::string_view receive() override;
};

#endif // MBUS_NETWORK_H
