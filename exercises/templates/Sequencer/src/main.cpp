// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <sml.hpp>
#include <cassert>
#include <iostream>

namespace sml = boost::sml;

namespace {
// events
struct release {};
struct ack {};
struct fin {};
struct timeout {};

// guards
const auto is_ack_valid = [](const ack&) { return true; };
const auto is_fin_valid = [](const fin&) { return true; };

// actions
const auto send_fin = [] { std::cout << "fin\n"; };
const auto send_ack = [] { std::cout << "ack\n"; };

struct hello_world {
  auto operator()() const {
    using namespace sml;
    // clang-format off
    return make_transition_table(
      *"established"_s + event<release> / send_fin = "fin wait 1"_s,
       "fin wait 1"_s + event<ack> [ is_ack_valid ] = "fin wait 2"_s,
       "fin wait 2"_s + event<fin> [ is_fin_valid ] / send_ack = "timed wait"_s,
       "timed wait"_s + event<timeout> / send_ack = X
    );
    // clang-format on
  }
};
}

int main() {
  using namespace sml;

  sm<hello_world> sm;
  static_assert(1 == sizeof(sm), "sizeof(sm) != 1b");
  assert(sm.is("established"_s));

  sm.process_event(release{});
  assert(sm.is("fin wait 1"_s));

  sm.process_event(ack{});
  assert(sm.is("fin wait 2"_s));

  sm.process_event(fin{});
  assert(sm.is("timed wait"_s));

  sm.process_event(timeout{});
  assert(sm.is(X));  // released
}
