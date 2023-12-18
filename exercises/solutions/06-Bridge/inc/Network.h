// Network.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef NETWORK_H
#define NETWORK_H

#include "I_Network.h"

#include <memory>
// Abstract base class that provides
// the Factory
//
class Network : public I_Network {
public:
  enum class NetType { Zigbee, MBus };

  static std::shared_ptr<I_Network> create(NetType type);

protected:
  virtual void openConnection() = 0;
  virtual void closeConnection() = 0;
  virtual void send(std::string_view str) = 0;
  virtual void receive() = 0;
};

#endif
