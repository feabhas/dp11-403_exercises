// MessageQueue.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef CONCURRENT_QUEUE_H
#define CONCURRENT_QUEUE_H

#include "MessageQueue.h"
#include <mutex>
#include <condition_variable>

class ConcurrentQueue : private MessageQueue {
public:
  ConcurrentQueue() = default;

  bool send(int in_val) {
    {
      std::unique_lock<std::mutex> guard(mtx);
      while(MessageQueue::is_full()) {
        has_space.wait(guard);
      }
      MessageQueue::send(in_val);
    }
    has_data.notify_all();
    return true;
  }

  Message receive() {
    Message msg {};
    {
      std::unique_lock<std::mutex> guard(mtx);
      while(MessageQueue::is_empty()) {
        has_data.wait(guard);
      }
      msg = MessageQueue::receive();
    }
    has_space.notify_all();
    return msg;
  }

  bool isEmpty() {
    return MessageQueue::is_empty();
  }
  
  // disable move and copy semantics
  ConcurrentQueue(const ConcurrentQueue &&) = delete;

private:
  std::mutex mtx{};
  std::condition_variable has_data;
  std::condition_variable has_space;
};

#endif // CONCURRENT_QUEUE_H
