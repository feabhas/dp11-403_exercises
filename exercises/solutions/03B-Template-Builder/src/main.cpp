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
  auto &log = EventLog::instance();

  log << "First event log entry";
  log << "subsequent entry...";

  EventLogParser<XMLBuilder> xml_parser{};
  if (auto product = xml_parser.construct("log.txt"); !product.empty()) {
    cout << product << '\n';
  }

  EventLogParser<HTMLBuilder> html_parser{};
  if (auto product = html_parser.construct("log.txt"); !product.empty()) {
    cout << product << '\n';
  }
}
