// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLog.h"
#include "EventLogParser.h"
#include "HTMLBuilder.h"
#include "XMLBuilder.h"

#include <iostream>

using std::cout;

int main() {
  EventLog::setLogFile("log.txt");
  EventLog &log = EventLog::instance();

  log << "First event log entry";
  log << "subsequent entry...";

  EventLogParser parser{};

  XMLBuilder xml_builder{}; // factory could be used here
  bind(parser, xml_builder);
  parser.construct("log.txt");

  cout << xml_builder.getProduct() << '\n';

  HTMLBuilder html_builder{};
  bind(parser, html_builder);
  parser.construct("log.txt");

  cout << html_builder.getProduct() << '\n';
}
