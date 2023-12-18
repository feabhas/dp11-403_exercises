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
  void setLogFile(std::string_view logfileName);
  void write(std::string_view str);
  EventLog &operator<<(std::string_view s);

  EventLog() = default;
  // Disable copy and moving
  //
  EventLog(const EventLog &) = delete;
  EventLog &operator=(const EventLog &) = delete;
  EventLog(EventLog &&) = delete;
  EventLog &operator=(EventLog &&) = delete;


private:
  std::ofstream log{};
  unsigned entryNumber{1};
  std::string filename{};
};

inline EventLog logger{};

#endif
