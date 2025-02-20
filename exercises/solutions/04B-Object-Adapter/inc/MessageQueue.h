// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "Messaging.h"
#include <array>

class MessageQueue : public IMessageQueue {
public:
  MessageQueue() = default;

  bool send(Message) override;
  bool send(int) override;
  bool send(int, std::string) override;
  Message receive() override;
  Message peek() override;
  void purge() override;

  MessageQueue(const MessageQueue &) = delete;
  MessageQueue(MessageQueue &&) = delete;
  MessageQueue &operator=(const MessageQueue &) = delete;
  MessageQueue &operator=(MessageQueue &&) = delete;

  static constexpr std::size_t capacity{8};

private:
  std::array<Message, capacity> circular_buffer{};
  std::size_t next_in{};
  std::size_t next_out{};
  unsigned size{};
};

#endif // MESSAGE_QUEUE_H
