// IRunnable.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef IRunnable_H
#define IRunnable_H

#include "RunPolicies.h"

class IRunnable {
public:
  virtual bool run() = 0;
  virtual ~IRunnable() {}
};

#endif // IRunnable_H
