// Sequencer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Sequencer.h"
#include "StateMachine.h"

void Sequencer::play() {
  if (auto new_state = current_state->on_play()) {
    current_state = std::move(new_state);
  }
}

void Sequencer::stop() {
  if (auto new_state = current_state->on_stop()) {
    current_state = std::move(new_state);
  }
}

void Sequencer::record() {
  if (auto new_state = current_state->on_record()) {
    current_state = std::move(new_state);
  }
}
