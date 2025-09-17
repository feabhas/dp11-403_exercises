// EventLogParser.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "EventLogParser.h"
#include "I_DocBuilder.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

void EventLogParser::construct(std::string_view filename) {
  if (not builder)
    throw std::runtime_error{"No builder found"};

  // ifstream logfile{filename.data()};
  ifstream logfile{"log.txt"};
  if (!logfile) {
    cerr << "can't open output file \"" << filename << "\"\n";
    return;
  }

  builder->preamble();

  while (!logfile.eof()) {

    string entry{};
    string date{};
    string text{};

    getline(logfile, entry);
    if (logfile.eof()) {
      break;
    }

    getline(logfile, date);
    if (logfile.eof()) {
      break;
    }

    getline(logfile, text);
    if (logfile.eof()) {
      break;
    }

    // TO DO:
    // Use the associated Builder object to construct
    // its product.
    //
    builder->heading(entry);
    builder->subheading(date);
    builder->body(text);
  }

  builder->postamble();
}

void bind(EventLogParser &parser, I_DocBuilder &builder) {
  parser.builder = &builder;
}
