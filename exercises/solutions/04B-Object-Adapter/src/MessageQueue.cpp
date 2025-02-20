// MessageQueue.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "MessageQueue.h"
#include <stdexcept>

bool MessageQueue::send(Message msg) {
  if (size == capacity)
    return false;
  circular_buffer[next_in++] = msg;
  if (next_in == capacity) {
    next_in = 0;
  }
  ++size;
  return true;
}

bool MessageQueue::send(int i) { return send(i, std::string{}); }

bool MessageQueue::send(int i, std::string str) {
  return send(Message{i, str});
}

Message MessageQueue::receive() {
  if (size == 0)
    throw std::runtime_error{"cannot read from an empty queue"};
  auto rv = circular_buffer[next_out++];
  if (next_out == capacity) {
    next_out = 0;
  }
  --size;
  return rv;
}

Message MessageQueue::peek() {
  if (size == 0)
    throw std::runtime_error{"cannot peek an empty queue"};
  return circular_buffer[next_out];
}

void MessageQueue::purge() {
  next_in = next_out = size = 0;
  // could be more expressive and fill
  // array with empty messages
  for (auto &e : circular_buffer) {
    e = Message{};
  }
}
