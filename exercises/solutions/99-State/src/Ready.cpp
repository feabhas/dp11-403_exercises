// Ready.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Ready.h"

#include <iostream>

#include "Playing.h"
#include "Recording.h"
// class Playing;
// class Recording;

Ready::Ready() { std::cout << "Ready \n"; }

StateMachine::ptr Ready::on_play() {
  return StateMachine::transition_to<Playing>();
}
StateMachine::ptr Ready::on_record() {
  return StateMachine::transition_to<Recording>();
}
StateMachine::ptr Ready::on_stop() { return StateMachine::no_transition(); }
