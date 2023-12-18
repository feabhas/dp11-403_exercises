// Network_concept.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_NETWORK_CONCEPT_H
#define I_NETWORK_CONCEPT_H

#include <string_view>
// -------------------------------------------
// Concept FOR NETWORK CLASSES
//
template<typename T, typename U>
concept Network_concept = requires(T c, U u) {
  c.openConnection();
  c.closeConnection();
  c.send(u);
  u = c.receive();
};

template<typename T>
concept Network = Network_concept<T,std::string_view>;

template<Network Ty, typename ...Param_Ty>
auto make_network(Param_Ty&&... param) {
  return Ty{std::forward<Param_Ty>(param)...};
}

#endif // I_NETWORK_CONCEPT_H
