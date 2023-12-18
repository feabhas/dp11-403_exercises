// WaterMeter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef WATER_METER_H
#define WATER_METER_H

#include "Meter.h"

class Water : public Meter {
public:
  explicit Water(I_Network &comms);

protected:
  void getReading() override;
};

#endif // WATER_METER_H
