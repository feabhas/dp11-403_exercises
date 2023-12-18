// Messaging.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGING_H
#define MESSAGING_H

#include <string>

struct Message {
  int value{};
  std::string label{};
};

class IMessageQueue {
public:
  virtual bool send(Message) = 0;
  virtual bool send(int) = 0;
  virtual bool send(int, std::string) = 0;
  virtual Message receive() = 0;
  virtual Message peek() = 0;
  virtual void purge() = 0;
  virtual ~IMessageQueue() = default;
};

#endif
