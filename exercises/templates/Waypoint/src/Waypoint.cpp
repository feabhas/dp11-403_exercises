// Waypoint.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Waypoint.h"
#include <iostream>
#include <string>

using namespace std;

Waypoint::Waypoint(double lat, double lon, string comment)
    : position{lat, lon}, ID{getID()}, notes{std::move(comment)} {}


void Waypoint::display() const {
  cout << ID << " ";
  position.display();
  cout << "\t";
  cout << notes;
}

void Waypoint::updateComment(string newComment) {
  notes = std::move(newComment);
}

unsigned int Waypoint::getID() { return Waypoint::nextID++; }
