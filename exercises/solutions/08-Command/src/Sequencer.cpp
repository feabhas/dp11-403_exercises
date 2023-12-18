// Sequencer.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Sequencer.h"

#include "ICommand.h"

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

void Sequencer::addCommand(ICommand &command) { commands.push_back(&command); }

void Sequencer::removeCommand(ICommand &command) {
  commands.erase(remove(begin(commands), end(commands), &command),
                 end(commands));
}

void Sequencer::execute() {
  for (auto &command : commands) {
    command->execute();
  }
}
