// EventLogParser.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENTLOGPARSER_H
#define EVENTLOGPARSER_H

#include <string_view>

class EventLogParser {
public:
  EventLogParser() = default;
  void construct(std::string_view filename);

private:
};

#endif // EVENTLOGPARSER_H
