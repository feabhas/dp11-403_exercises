// ICommand.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ICOMMAND_H
#define ICOMMAND_H

class ICommand {
public:
  virtual void execute() = 0;
  virtual ~ICommand() = default;
};

#endif
