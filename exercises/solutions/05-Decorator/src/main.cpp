// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "AltitudeDecorator.h"
#include "SymbolDecorator.h"
#include "Track.h"
#include "Waypoint.h"
#include <iostream>

using std::cout;

int main() {
  cout << "Design Patterns" << '\n';

  Waypoint wp1{51.498950, -1.594833, "Baydon"};
  Waypoint wp2{51.575032, -1.565818, "Uffingham"};
  Waypoint wp3{51.482277, -1.536622, "Feabhas"};

  Track track1 = {&wp1, &wp2, &wp3}; // initializer_list
  track1.follow();

  SymbolDecorator symbol_wp{wp2, SymbolDecorator::dot};
  AltitudeDecorator alt_waypoint{wp3, 150};

  AltitudeDecorator sym_alt_wp{symbol_wp, 200};
  SymbolDecorator alt_sym_wp{alt_waypoint, SymbolDecorator::dot};

  Track track2{};

  bind(track2, wp1);
  bind(track2, wp3);
  bind(track2, symbol_wp);
  bind(track2, alt_waypoint);
  bind(track2, sym_alt_wp);
  bind(track2, alt_sym_wp);

  track2.follow();
}
/*
sym_alt_wp.display()

alt::display
  -> decotor::display
    -> Symbol::display
      -> Decorator::display
        - > Waypoint::display
        <-
      <-
    <-
  <-
<-

*/
