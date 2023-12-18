// StateMachine.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef StateMachine_H
#define StateMachine_H

#include <memory>

class StateMachine {
public:
  using ptr = std::unique_ptr<StateMachine>;

  static ptr initialise();
  // static void terminate(ptr stateMachine);

  virtual ptr on_play() = 0;
  virtual ptr on_record() = 0;
  virtual ptr on_stop() = 0;

  virtual ~StateMachine() = default;

protected:
  ptr no_transition() { return nullptr; }

  template <typename State_Ty> StateMachine::ptr transition_to();
};

template <typename State_Ty> StateMachine::ptr StateMachine::transition_to() {
  return std::make_unique<State_Ty>();
}

#endif // StateMachine_H
