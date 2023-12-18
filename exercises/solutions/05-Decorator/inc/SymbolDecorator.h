// SymbolDecorator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef SYMBOL_DECORATORS_H
#define SYMBOL_DECORATORS_H

#include "Decorator.h"
#include "I_Waypoint.h"

class SymbolDecorator : public Decorator {
public:
  enum Symbol { dot, flag, camp, circle_x, first_aid, back_track };

public:
  SymbolDecorator(I_Waypoint &theObject, Symbol newSymbol);

protected:
  // Interface realisation
  //
  void display() const override;

private:
  Symbol symbol{};
};

#endif // SYMBOL_DECORATORS_H
