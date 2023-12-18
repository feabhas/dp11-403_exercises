// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "UI.h"

#include <iostream>

using std::cout;

int main() {
  cout << "Design Patterns" << '\n';

  Display display{};
  UI ui{display};

  auto run_policy = [](IRunnable &runnable) {
    bool finished{};
    do {
      finished = runnable.run();
    } while (!finished);
  };

  std::thread t2{run_policy, std::ref(display)};

  this_thread::sleep_for(1s);

  std::thread t1{run_policy, std::ref(ui)};

  t1.join();
  t2.join();
}
