// StateMachine.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "StateMachine.h"
#include "Ready.h"
// class Ready;

StateMachine::ptr StateMachine::initialise() {
  return std::make_unique<Ready>();
}
