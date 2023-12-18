// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Behaviour.h"
#include "Counter.h"
#include "Hardware.h"
#include "ICommand.h"
#include "Sequencer.h"
#include "Timer.h"

#include <iostream>

using namespace std;

constexpr auto delay {500ms};

int main() {
  Motor motor{};
  MotorBehaviour toggle{motor};

  Timer timer{delay, toggle};
  timer.start();

  cout << ">>>>>>>>> changing context\n";
  SevenSeg sevenseg{};
  Counter countup{sevenseg};

  connect(timer, countup);
  timer.start();

  cout << ">>>>>>>>> changing context\n";
  Sequencer sequencer{};
  sequencer.addCommand(toggle);
  sequencer.addCommand(countup);

  connect(timer, sequencer);
  timer.start();

  // cout << ">>>>>>>>> changing context\n";
  // sequencer.removeCommand(toggle);
  // timer.start();
}
