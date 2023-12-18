// EventLog.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENTLOG_H
#define EVENTLOG_H

#include <fstream>
#include <string_view>

class EventLog {
public:
  static void setLogFile(std::string_view logfileName);
  static EventLog &instance();

  void write(std::string_view str);
  EventLog &operator<<(std::string_view s);

  // Disable copy and moving
  //
  EventLog(const EventLog &) = delete;
  EventLog &operator=(const EventLog &) = delete;
  EventLog(EventLog &&) = delete;
  EventLog &operator=(EventLog &&) = delete;

protected:
  EventLog();

private:
  std::ofstream log{};

  unsigned entryNumber{1};
  static inline std::string filename{};
};

#endif
