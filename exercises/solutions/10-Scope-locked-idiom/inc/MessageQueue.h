// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "Buffer.h"

#include <mutex>

template <typename T, size_t sz = 16>
class MessageQueue : private Buffer<T, sz> {
public:
  MessageQueue();
  void post(const T &in_val);
  T get();
  bool isEmpty();

  MessageQueue(const MessageQueue &) = delete;
  MessageQueue(const MessageQueue &&) = delete;
  MessageQueue &operator=(const MessageQueue &) = delete;
  MessageQueue &operator=(const MessageQueue &&) = delete;

private:
  std::mutex mtx{};
};

template <typename T, size_t sz>
MessageQueue<T, sz>::MessageQueue() : Buffer<T, sz>() {}

template <typename T, size_t sz>
void MessageQueue<T, sz>::post(const T &in_val) {
  std::lock_guard<std::mutex> guard{mtx};

  Buffer<T, sz>::add(in_val);
}

template <typename T, size_t sz> T MessageQueue<T, sz>::get() {
  T val{};
  {
    std::lock_guard<std::mutex> guard{mtx};
    Buffer<T, sz>::get(val);
  }
  return val;
}

template <typename T, size_t sz> bool MessageQueue<T, sz>::isEmpty() {
  return Buffer<T, sz>::isEmpty();
}

using Queue = MessageQueue<int, 16>;

#endif // MESSAGE_QUEUE_H
