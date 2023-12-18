// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLog.h"
#include "EventLogParser.h"
#include <iostream>

void f() {
  auto &local_log = EventLog::instance();
  local_log << "world";
}

int main() {
  try {
    [[maybe_unused]] auto &log = EventLog::instance();
  } catch (std::exception &e) {
    std::cout << e.what() << " Can't create instance without logfile set\n";
  }

  EventLog::setLogFile("log.txt");
  auto &log = EventLog::instance();

  log.write("Hello");
  f();

  // EventLogParser elp{};
  // elp.construct("log.txt");
}

// Should create a file "log.txt" containing
// (for example) the following:
// Log entry: 0
// Tue Apr 27 10:17:43 2021
// Hello
// Log entry: 1
// Tue Apr 27 10:17:43 2021
// world
