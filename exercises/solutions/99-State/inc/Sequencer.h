// Sequencer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Sequencer_H
#define Sequencer_H

#include "StateMachine.h"

class Sequencer {
public:
  Sequencer() = default;

  void play();
  void stop();
  void record();

private:
  StateMachine::ptr current_state{StateMachine::initialise()};
};

#endif // Sequencer_H
