// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLog.h"
#include "EventLogParser.h"
#include <iostream>

void f() {
  // auto &local_log = EventLog::instance();
  logger << "world";
}

int main() {
  try {
    logger.write("Hello");
  } catch (std::exception &e) {
    std::cout << e.what() << " Can't create instance without logfile set\n";
  }

  logger.setLogFile("log.txt");
  // auto &log = EventLog::instance();

  logger.write("Hello");
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
