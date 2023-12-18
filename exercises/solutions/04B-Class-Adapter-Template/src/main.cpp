// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "MessageQueue.h"
#include <iostream>

using std::cout;

constexpr int count = 10;

int main() {
  MessageQueue<Message> queue{};
  auto fill_mq = [&queue]() {
    int i{};
    do {
      if (auto successful = queue.send(i++, "Data"); not successful)
        break;
    } while (true);
  };

  auto read_to_empty = [&queue]() {
    do {
      try {
        auto [value, label] = queue.receive();
        std::cout << label << ": " << value << '\n';
      } catch (std::exception &ex) {
        break;
      }
    } while (true);
  };

  fill_mq();

  try {
    auto [value, label] = queue.peek();
    std::cout << label << ": " << value << '\n';
  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
  }

  read_to_empty();

  fill_mq();
  queue.purge();
  read_to_empty();
}
