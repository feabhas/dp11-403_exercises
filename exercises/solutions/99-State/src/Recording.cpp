// Recording.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Recording.h"

#include <iostream>

#include "Ready.h"
// class Ready;

Recording::Recording() { std::cout << "Recording... \n"; }

StateMachine::ptr Recording::on_play() { return StateMachine::no_transition(); }
StateMachine::ptr Recording::on_record() {
  return StateMachine::no_transition();
}
StateMachine::ptr Recording::on_stop() {
  return StateMachine::transition_to<Ready>();
}
