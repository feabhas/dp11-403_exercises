// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "Messaging.h"
#include <array>
#include <stdexcept>

template <typename Ty, std::size_t sz = 8>
class MessageQueue : public IMessageQueue, private std::array<Ty, sz> {
public:
  static constexpr std::size_t capacity{sz};
  MessageQueue() = default;

  MessageQueue(const MessageQueue &) = delete;
  MessageQueue(MessageQueue &&) = delete;
  MessageQueue &operator=(const MessageQueue &) = delete;
  MessageQueue &operator=(MessageQueue &&) = delete;

  bool send(Message msg) override {
    if (size == capacity)
      return false;
    std::array<Message, capacity>::at(next_in++) = msg;
    if (next_in == capacity) {
      next_in = 0;
    }
    ++size;
    return true;
  }

  bool send(int i) override { return send(i, std::string{}); }

  bool send(int i, std::string str) override { return send(Message{i, str}); }

  Message receive() override {
    if (size == 0)
      throw std::runtime_error{"cannot read from an empty queue"};
    auto rv = std::array<Message, sz>::at(next_out++);
    if (next_out == sz) {
      next_out = 0;
    }
    --size;
    return rv;
  }

  Message peek() override {
    if (size == 0)
      throw std::runtime_error{"cannot peek an empty queue"};
    return std::array<Message, sz>::at(next_out);
  }

  void purge() override {
    next_in = next_out = size = 0;
    // could be more expressive and fill
    // array with empty messages
    std::array<Message, sz> local{};
    std::swap(local, *this);
  }

private:
  // std::array<Message, capacity> circular_buffer{};
  std::size_t next_in{};
  std::size_t next_out{};
  unsigned size{};
};

#endif // MESSAGE_QUEUE_H
