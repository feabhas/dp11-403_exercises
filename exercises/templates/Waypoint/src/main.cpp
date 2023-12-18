// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Track.h"
#include "Waypoint.h"
#include <iostream>

int main() {
  std::cout << "Design Patterns\n";

  Waypoint wp1{51.498950, -1.594833, "Baydon"};
  Waypoint wp2{51.575032, -1.565818, "Uffingham"};
  Waypoint wp3{51.482277, -1.536622, "Feabhas"};

  Track track1 = {&wp1, &wp2, &wp3}; // initializer_list
  track1.follow();


  Track track2{};

  bind(track2, wp1);
  bind(track2, wp3);

  track2.follow();
}
