// Playing.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Playing.h"

#include <iostream>

#include "Paused.h"
#include "Ready.h"

Playing::Playing() { std::cout << "Playing... \n"; }

StateMachine::ptr Playing::on_play() {
  return StateMachine::transition_to<Paused>();
}
StateMachine::ptr Playing::on_record() { return StateMachine::no_transition(); }
StateMachine::ptr Playing::on_stop() {
  return StateMachine::transition_to<Ready>();
}
