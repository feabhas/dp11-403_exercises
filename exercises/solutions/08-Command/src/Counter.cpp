// Counter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Counter.h"

#include "Hardware.h"
#include "ICommand.h"

Counter::Counter(SevenSeg &sevenSeg) : context{sevenSeg}, isUpdateTime{true} {}

constexpr unsigned max_count = 10U;

void Counter::execute() {
  if (isUpdateTime) {
    context.display(count);
    ++count;
    if (count == max_count)
      count = 0;
  }
  isUpdateTime = not isUpdateTime;
}
