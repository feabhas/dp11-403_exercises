// Playing.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Playing_H
#define Playing_H

#include "StateMachine.h"

class Playing : public StateMachine {
public:
  Playing();
  ~Playing() override = default;
  StateMachine::ptr on_play() override;
  StateMachine::ptr on_record() override;
  StateMachine::ptr on_stop() override;
};

#endif // Playing_H
