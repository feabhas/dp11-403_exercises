// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "ConcurrentQueue.h"
#include "UI.h"

int main() {
  ConcurrentQueue queue{};

  UI ui{queue};
  Display display{queue};

  auto run_policy = [](IRunnable &runnable) {
    bool finished{};
    do {
      finished = runnable.run();
    } while (!finished);
  };

  std::thread t1{run_policy, std::ref(ui)};
  std::thread t2{run_policy, std::ref(display)};

  t1.join();
  t2.join();
}
