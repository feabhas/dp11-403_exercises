// I_Waypoint.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_Waypoint_H
#define I_Waypoint_H

class I_Waypoint {
public:
  virtual void display() const = 0;
  virtual ~I_Waypoint() = default;
};

#endif // I_Waypoint_H
