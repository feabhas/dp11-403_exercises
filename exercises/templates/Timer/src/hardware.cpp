// hardware.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Hardware.h"
#include <iostream>

using std::cout;

void Motor::on() { cout << "Motor on\n"; }

void Motor::off() { cout << "Motor off\n"; }

void SevenSeg::display(unsigned i) {
  cout << "Seven segment showing : " << i << '\n';
}
