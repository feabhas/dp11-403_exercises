// I_Meter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_METER_H
#define I_METER_H

// -------------------------------------------
// INTERFACE FOR METER CLASSES
//
class I_Meter {
public:
  virtual void getReading() = 0;
  virtual ~I_Meter() = default;
};

#endif // I_METER_H
