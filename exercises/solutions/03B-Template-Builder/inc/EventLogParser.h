// EventLogParser.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef EVENTLOGPARSER_H
#define EVENTLOGPARSER_H

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

template <class DocBuilder> class EventLogParser {
public:
  EventLogParser() = default;
  using product = typename DocBuilder::product_t;

  product construct(std::string_view filename) {
    ifstream logfile{filename.data()};
    // ifstream logfile{"log.txt"};
    if (!logfile) {
      cerr << "can't open output file \"" << filename << "\"\n";
      return {};
    }

    builder.preamble();

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
      
      builder.heading(entry);
      builder.subheading(date);
      builder.body(text);
    }

    builder.postamble();

    return builder.getProduct();
  }

private:
  // Composition: Parser has a Builder
  DocBuilder builder{};
};

#endif // EVENTLOGPARSER_H
