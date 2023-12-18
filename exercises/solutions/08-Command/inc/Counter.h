// Counter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Counter_H
#define Counter_H

class SevenSeg;

#include "ICommand.h"

class Counter : public ICommand {
public:
  explicit Counter(SevenSeg &sevenSeg);

protected:
  void execute() override;

private:
  SevenSeg &context;

  unsigned count{};
  bool isUpdateTime{};
};

#endif // Counter_H
