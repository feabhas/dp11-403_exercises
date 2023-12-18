// Network.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef NETWORK_H
#define NETWORK_H

#include "I_Network.h"

#include <memory>
#include <string_view>
// Base class that provides
// the Factory
//
class Network_maker {
public:
  enum class NetType { Zigbee, MBus };
  static std::unique_ptr<I_Network> create(NetType type);
  static std::unique_ptr<I_Network> create(std::string_view type);
};

template<typename Ty, typename ...Param_Ty>
auto make_network(Param_Ty&&... param) {
  return Ty{std::forward<Param_Ty>(param)...};
}

#endif
