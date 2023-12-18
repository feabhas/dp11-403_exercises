// Ready.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Ready_H
#define Ready_H

#include "StateMachine.h"

class Ready : public StateMachine {
public:
  Ready();
  ~Ready() override = default;
  StateMachine::ptr on_play() override;
  StateMachine::ptr on_record() override;
  StateMachine::ptr on_stop() override;
};

#endif // Ready_H
