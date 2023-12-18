// I_Observer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_Observer_H
#define I_Observer_H

class I_Observer {
public:
  virtual void update() = 0;
  virtual ~I_Observer() = default;
};

#endif // I_Observer_H
