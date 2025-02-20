// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "Messaging.h"
#include <array>

constexpr std::size_t queue_capacity{8};

class MessageQueue : public IMessageQueue,
                     private std::array<Message, queue_capacity> {
public:
  static constexpr std::size_t capacity{queue_capacity};

  MessageQueue() = default;

  bool send(Message) override;
  bool send(int) override;
  bool send(int, std::string) override;
  Message receive() override;
  Message peek() override;
  void purge() override;

  bool is_empty() { return size == 0; }
  bool is_full() { return size == capacity; }

  MessageQueue(const MessageQueue &) = delete;
  MessageQueue(MessageQueue &&) = delete;
  MessageQueue &operator=(const MessageQueue &) = delete;
  MessageQueue &operator=(MessageQueue &&) = delete;

private:
  std::size_t next_in{};
  std::size_t next_out{};
  unsigned size{};
};

#endif // MESSAGE_QUEUE_H
