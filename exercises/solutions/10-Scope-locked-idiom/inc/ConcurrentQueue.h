// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_H

#include "MessageQueue.h"
#include <mutex>

class ConcurrentQueue : private MessageQueue {
public:
  ConcurrentQueue() = default;

  bool send(int in_val) {
    std::lock_guard<std::mutex> guard { mtx };
    return MessageQueue::send(in_val);
  }

  Message receive() {
    std::lock_guard<std::mutex> guard { mtx };
    return MessageQueue::receive();
  }

  bool isEmpty() {
    return MessageQueue::is_empty();
  }
  
  // disable move and copy semantics
  ConcurrentQueue(const ConcurrentQueue &&) = delete;

private:
  std::mutex mtx{};
};

#endif // CONCURRENT_QUEUE_H
