// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Sequencer.h"

int main() {
  Sequencer sequence{};

  sequence.play();
  sequence.play(); // paused
  sequence.play(); // playing
  sequence.stop();
  sequence.record();
  sequence.play(); // no transition
  sequence.stop();
  sequence.stop(); // no transition
}
