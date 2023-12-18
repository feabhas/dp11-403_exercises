// Meter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef METER_H
#define METER_H

#include "I_Meter.h"
#include <string>

// ----------------------------------------------------------
// Base class for meters.  Contains the Bridge to the
// networking mechanisms.
//
class I_Network; // Forward reference

class Meter : public I_Meter {
public:
  Meter(I_Network &comms);
  virtual ~Meter();

protected:
  virtual void getReading() = 0;

protected:
  // Networking operations, which will be forwarded
  // over the bridge and handled by a concrete networking
  // object.
  //
  void connect();
  void disconnect();
  void Tx(const std::string &str);
  void Rx();

private:
  I_Network *network{};
};

#endif // METER_H
