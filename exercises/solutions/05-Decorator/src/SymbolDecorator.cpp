// SymbolDecorator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "SymbolDecorator.h"
#include <iostream>
#include <unordered_map>

using namespace std;

SymbolDecorator::SymbolDecorator(I_Waypoint &theObject, Symbol newSymbol)
    : Decorator{theObject}, symbol{newSymbol} {}

namespace {
unordered_map<SymbolDecorator::Symbol, std::string> symbol_str = {
    {SymbolDecorator::Symbol::dot, "DOT"},
    {SymbolDecorator::Symbol::flag, "FLAG"},
    {SymbolDecorator::Symbol::camp, "CAMP"},
    {SymbolDecorator::Symbol::circle_x, "CIRCLE_X"},
    {SymbolDecorator::Symbol::first_aid, "FIRST_AID"},
    {SymbolDecorator::Symbol::back_track, "BACK_TRACK"}};
}

void SymbolDecorator::display() const {
  // Call on the decorated object's functionality
  //
  Decorator::display();

  // Now add any new behaviour.
  //
  cout << "\t" << symbol_str[symbol];
}
