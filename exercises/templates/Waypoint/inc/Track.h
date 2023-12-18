// Track.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef TRACK_H
#define TRACK_H
#include <vector>

// Forward reference
//
class I_Waypoint;

class Track {
public:
  Track();
  Track(std::initializer_list<I_Waypoint *> wp_ptrs);
  void follow() const;

private:
  friend bool bind(Track &track, I_Waypoint &navpoint);

  static constexpr unsigned maxpoints{16};
  std::vector<I_Waypoint *> navpoints{};
};

#endif // TRACK_H
