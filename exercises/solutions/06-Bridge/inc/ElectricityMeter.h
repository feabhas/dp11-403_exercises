// ElectricityMeter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ELEC_METER_H
#define ELEC_METER_H

#include "Meter.h"

class Electricity : public Meter {
public:
  explicit Electricity(I_Network &comms);

protected:
  void getReading() override;
};

#endif // ELEC_METER_H
