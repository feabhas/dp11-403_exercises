// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include "Buffer.h"

#include <condition_variable>
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
  std::condition_variable has_data;
  std::condition_variable has_space;
};

template <typename T, size_t sz>
MessageQueue<T, sz>::MessageQueue() : Buffer<T, sz>() {}

template <typename T, size_t sz>
void MessageQueue<T, sz>::post(const T &in_val) {
  unique_lock<mutex> guard(mtx);
  while (Buffer<T, sz>::add(in_val) == Buffer<T, sz>::Error::FULL) {
    has_space.wait(guard);
  }

  // Buffer<T, sz>::add(in_val);
  has_data.notify_all();
}

template <typename T, size_t sz> T MessageQueue<T, sz>::get() {
  T val{};
  unique_lock<mutex> guard(mtx);
  // while (isEmpty()) {
  //   has_data.wait(guard);
  // }
  has_data.wait(guard, [this] { return !isEmpty(); });

  Buffer<T, sz>::get(val);

  has_space.notify_all();
  return val;
}
template <typename T, size_t sz> bool MessageQueue<T, sz>::isEmpty() {
  return Buffer<T, sz>::isEmpty();
}
#endif // MESSAGE_QUEUE_H
