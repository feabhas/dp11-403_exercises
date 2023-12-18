// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Client.h"
#include "ElectricityMeter.h"
#include "GasMeter.h"
#include "I_Meter.h"
#include "Network.h"
#include "WaterMeter.h"


int main()
{

  auto pZComms = Network::create(Network::NetType::Zigbee);
  auto pMComms = Network::create(Network::NetType::MBus);

  Electricity elec_meter{*pZComms};
  Gas gas_meter{*pZComms};
  Water water_meter{*pZComms};

  Client controller = {&elec_meter, &gas_meter, &water_meter};

  controller.read();
}
