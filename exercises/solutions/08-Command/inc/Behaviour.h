// Behaviour.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MotorBehaviour_H
#define MotorBehaviour_H

#include "ICommand.h"

class Motor;

class MotorBehaviour : public ICommand {
public:
  explicit MotorBehaviour(Motor &motor) : context{motor} {}

protected:
  void execute() override;

private:
  Motor &context;
  bool isOn{};
};

#endif // MotorBehaviour_H
