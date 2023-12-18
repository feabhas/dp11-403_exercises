// Waypoint.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef WAYPOINT_H
#define WAYPOINT_H

#include "I_Waypoint.h"
#include "Position.h"

#include <string>

class Waypoint : public I_Waypoint {
public:
  Waypoint() = default;
  Waypoint(double lat, double lon, std::string comment);

  void updateComment(std::string newComment);

protected:
  // Interface realisation
  //
  void display() const override;

private:
  unsigned int getID();

private:
  Position position{};
  unsigned int ID{};
  std::string notes{};

private:
  static inline unsigned int nextID{1};
};

// class WaypointAdaptor : public I_Waypoint {
//   Waypoint wp{};

// };
#endif // WAYPOINT_H
