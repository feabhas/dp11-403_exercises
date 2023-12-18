// I_Network.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_NETWORK_H
#define I_NETWORK_H

// -------------------------------------------
// INTERFACE FOR NETWORK CLASSES
//
#include <string_view>

class I_Network {
public:
  virtual void openConnection() = 0;
  virtual void closeConnection() = 0;
  virtual void send(std::string_view str) = 0;
  virtual std::string_view receive() = 0;
  virtual ~I_Network() = default;
};

#endif // I_NETWORK_H
