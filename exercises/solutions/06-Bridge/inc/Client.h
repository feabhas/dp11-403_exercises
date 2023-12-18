// Client.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Client_H
#define Client_H

#include <vector>

class I_Meter;

class Client {
public:
  Client(std::initializer_list<I_Meter *> meters);
  void read();

private:
  std::vector<I_Meter *> devices{};
  friend void connect(Client &c, I_Meter &dev);
};

#endif // Client_H
