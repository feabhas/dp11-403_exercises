// Paused.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Paused_H
#define Paused_H

#include "StateMachine.h"

class Paused : public StateMachine {
public:
  Paused();
  ~Paused() override = default;
  StateMachine::ptr on_play() override;
  StateMachine::ptr on_record() override;
  StateMachine::ptr on_stop() override;
};

#endif // Paused_H
