// Subject.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef Subject_H
#define Subject_H

class I_Observer;

#include <vector>

class Subject {
public:
  void attach(I_Observer &obs);

protected:
  void notify();

private:
  std::vector<I_Observer *> observers;
};

#endif // Subject_H
