// GasMeter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GAS_METER_H
#define GAS_METER_H

#include "Meter.h"

class Gas : public Meter {
public:
  explicit Gas(I_Network &comms);

protected:
  void getReading() override;
};

#endif // GAS_METER_H
