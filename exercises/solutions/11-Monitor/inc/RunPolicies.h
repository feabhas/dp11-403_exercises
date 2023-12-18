// RunPolicies.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef RUNPOLICIES_H
#define RUNPOLICIES_H

#include "IRunnable.h"
#include <thread>

template <typename RunnableType> class ToCompletion {
public:
  explicit ToCompletion(RunnableType &obj) : runObject(obj) {}

  bool operator()() {
    bool done{};
    do {
      done = runObject();
    } while (!done);
    return done;
  }

private:
  RunnableType &runObject;
};

template <typename RunnableType> class Once {
public:
  explicit Once(RunnableType &obj) : runObject(obj) {}

  bool operator()() { return runObject(); }

private:
  RunnableType &runObject;
};

template <typename RunnableType> class Forever {
public:
  explicit Forever(RunnableType &obj) : runObject(obj) {}

  bool operator()() {
    while (true) {
      runObject();
      std::this_thread::yield();
    }
    return false;
  }

private:
  RunnableType &runObject;
};

#endif // RUNPOLICIES_H
