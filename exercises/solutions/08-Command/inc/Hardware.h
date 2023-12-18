// Hardware.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef HARDWARE_H
#define HARDWARE_H

// ----------------------------------------------------------
// Library code: treat as inviolate if possible.
//
class Motor {
public:
  void on();
  void off();
};

class SevenSeg {
public:
  void display(unsigned i);
};

#endif
