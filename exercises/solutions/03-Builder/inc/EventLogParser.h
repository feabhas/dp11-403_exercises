// EventLogParser.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENTLOGPARSER_H
#define EVENTLOGPARSER_H

#include <memory>
#include <string>

class I_DocBuilder;

class EventLogParser {
public:
  EventLogParser() = default;
  void construct(std::string_view fileName);

private:
  // Binding to Builder
  //
  friend void bind(EventLogParser &parser, I_DocBuilder &builder);

  I_DocBuilder *builder{};
};

#endif // EVENTLOGPARSER_H
