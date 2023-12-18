// Recording.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Recording_H
#define Recording_H

#include "StateMachine.h"

class Recording : public StateMachine {
public:
  Recording();
  ~Recording() override = default;
  StateMachine::ptr on_play() override;
  StateMachine::ptr on_record() override;
  StateMachine::ptr on_stop() override;
};

#endif // Recording_H
