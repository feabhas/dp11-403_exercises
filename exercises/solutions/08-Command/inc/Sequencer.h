// Sequencer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Sequencer_H
#define Sequencer_H

#include "ICommand.h"
#include <list>

class Sequencer : public ICommand {
public:
  Sequencer() = default;
  void addCommand(ICommand &command);
  void removeCommand(ICommand &command);

protected:
  void execute();

private:
  std::list<ICommand *> commands{};
};

#endif // Sequencer_H
