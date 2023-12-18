// Track.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Track.h"
#include "I_Waypoint.h"
#include <algorithm>
#include <functional>
#include <iostream>

Track::Track() {
  navpoints.reserve(16); // Pre-allocate memory
}

Track::Track(std::initializer_list<I_Waypoint *> wp_ptrs) {
  if (wp_ptrs.size() < maxpoints) {
    navpoints.insert(navpoints.end(), wp_ptrs.begin(), wp_ptrs.end());
  }
}

void Track::follow() const {
  for (auto &np : navpoints) {
    np->display();
    std::cout << '\n';
  }
}

bool bind(Track &track, I_Waypoint &navpoint) {
  if (track.navpoints.size() == track.maxpoints)
    return false;
  track.navpoints.push_back(&navpoint);
  return true;
}
