// Paused.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Paused.h"

#include <iostream>

#include "Playing.h"
#include "Ready.h"

Paused::Paused() { std::cout << "Paused... \n"; }

StateMachine::ptr Paused::on_play() {
  return StateMachine::transition_to<Playing>();
}
StateMachine::ptr Paused::on_record() { return StateMachine::no_transition(); }
StateMachine::ptr Paused::on_stop() {
  return StateMachine::transition_to<Ready>();
}
