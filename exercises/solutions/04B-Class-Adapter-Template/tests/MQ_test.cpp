// MQ_test.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::_;
using ::testing::A;
using ::testing::ContainsRegex;
using ::testing::NaggyMock;
using ::testing::NiceMock;
using ::testing::Return;
using ::testing::StartsWith;
using ::testing::StrictMock;

#include "MessageQueue.h"

#include <exception>
#include <iostream>

class MQ_Tests : public ::testing::Test {
protected:
  MQ_Tests() {
    // Do set-up work for each test here.
  }
  MessageQueue<Message> queue{};
};

static const auto fill_Q = [](auto &queue, std::size_t count) {
  for (std::size_t idx{}; idx < count; ++idx) {
    auto str = std::string{"Data" + std::to_string(idx)};
    ASSERT_TRUE(queue.send(idx, str));
  }
};

TEST_F(MQ_Tests, read_from_empty) {
  ASSERT_THROW(queue.receive(), std::runtime_error);
}

TEST_F(MQ_Tests, peak_from_empty) {
  ASSERT_THROW(queue.peek(), std::runtime_error);
}

TEST_F(MQ_Tests, write_one_and_peek) {
  ASSERT_TRUE(queue.send(1, "Data"));
  auto [value, label] = queue.peek();
  ASSERT_EQ("Data", label);
  ASSERT_EQ(1, value);
}

TEST_F(MQ_Tests, write_one_and_read) {
  GTEST_SKIP();
  ASSERT_TRUE(queue.send(1, "Data"));
  auto [value, label] = queue.receive();
  ASSERT_EQ(1, value);
  ASSERT_EQ("Data", label);
}

TEST_F(MQ_Tests, write_two_and_read_back) {
  GTEST_SKIP();
  ASSERT_TRUE(queue.send(1, "Data1"));
  ASSERT_TRUE(queue.send(2, "Data2"));
  {
    auto [value, label] = queue.receive();
    ASSERT_EQ(1, value);
    ASSERT_EQ("Data1", label);
  }
  {
    auto [value, label] = queue.receive();
    ASSERT_EQ("Data2", label);
    ASSERT_EQ(2, value);
  }
  ASSERT_THROW(queue.receive(), std::runtime_error);
}

TEST_F(MQ_Tests, write_to_full) {
  // for(std::size_t idx{}; idx < queue.capacity; ++ idx){
  //     ASSERT_TRUE(queue.send(idx, std::string{}));
  // }
  fill_Q(queue, queue.capacity);

  ASSERT_FALSE(queue.send(0, std::string{}));
}

TEST_F(MQ_Tests, read_from_full_to_empty) {
  // for(std::size_t idx{}; idx < queue.capacity; ++ idx){
  //     auto str = std::string{"Data"+std::to_string(idx)};
  //    queue.send(idx, str);
  // }
  fill_Q(queue, queue.capacity);

  for (std::size_t idx{}; idx < queue.capacity; ++idx) {
    auto [value, label] = queue.receive();
    ASSERT_EQ(idx, value);
    auto str = std::string{"Data" + std::to_string(idx)};
    ASSERT_EQ(str, label);
  }
  ASSERT_THROW(queue.receive(), std::runtime_error);
}

TEST_F(MQ_Tests, wrap_around_test) {
  // for(std::size_t idx{}; idx < queue.capacity; ++idx){
  //     auto str = std::string{"Data"+std::to_string(idx)};
  //    queue.send(idx, str);
  // }
  fill_Q(queue, queue.capacity);

  // half empty
  for (std::size_t idx{}; idx < queue.capacity / 2; ++idx) {
    auto [value, label] = queue.receive();
    ASSERT_EQ(idx, value);
    auto str = std::string{"Data" + std::to_string(idx)};
    ASSERT_EQ(str, label);
  }

  // refill to full using exception to exit loop, will force wrap around on send
  try {
    for (std::size_t idx{}; idx < queue.capacity; ++idx) {
      auto str = std::string{"Data" + std::to_string(idx)};
      queue.send(idx, str);
    }
  } catch (std::exception &ex) {
  }

  // now empty which will force wrap around on receive
  for (std::size_t idx{}; idx < queue.capacity; ++idx) {
    [[maybe_unused]] auto [value, label] = queue.receive();
  }

  // check it's now empty
  ASSERT_THROW(queue.receive(), std::runtime_error);
}

TEST_F(MQ_Tests, peek_after_read) {
  fill_Q(queue, queue.capacity);

  constexpr auto half_queue = queue.capacity / 2;

  // Half empty
  for (std::size_t idx{}; idx < half_queue; ++idx) {
    [[maybe_unused]] auto [value, label] = queue.receive();
  }

  // Peek at current head
  {
    auto [value, label] = queue.peek();
    ASSERT_EQ(half_queue, value);
    auto str = std::string{"Data" + std::to_string(half_queue)};
    ASSERT_EQ(str, label);
  }

  // now read it to check peek hasn't altered any internal state
  {
    auto [value, label] = queue.receive();
    ASSERT_EQ(half_queue, value);
    auto str = std::string{"Data" + std::to_string(half_queue)};
    ASSERT_EQ(str, label);
  }
}

TEST_F(MQ_Tests, read_after_purge) {
  fill_Q(queue, queue.capacity);

  queue.purge();

  ASSERT_THROW(queue.receive(), std::runtime_error);
}
