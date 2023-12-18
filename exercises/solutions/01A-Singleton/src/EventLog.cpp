// EventLog.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLog.h"
#include "DateTime.h"
#include <exception>
#include <fstream>
#include <iostream>

using std::cout;
using std::ios_base;
using std::ofstream;
using std::string;

void EventLog::setLogFile(std::string_view logfileName) {
  filename = logfileName;
}

EventLog &EventLog::instance() {
  if (filename.empty()) {
    throw std::runtime_error(
        "No logfile set!"); // no EventLog instance created!
  }
  static EventLog instance{};

  return instance;
}

void EventLog::write(std::string_view str) {
  log.open(filename.c_str(), ios_base::app);
  log << "Log entry: " << entryNumber++ << '\n';
  log << DateTime::now();
  log << str.data() << '\n';
  log.close();
}

EventLog &EventLog::operator<<(std::string_view s) {
  write(s);
  return *this;
}

EventLog::EventLog() : log{ofstream{filename.c_str(), ios_base::trunc}} {
  log.close();
}
