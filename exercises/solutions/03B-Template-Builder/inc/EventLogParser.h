// EventLogParser.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#ifdef __cpp_concepts
// -------------------------------------------
// Concept FOR BUILDER CLASSES
//
template <typename T, typename U>
concept builder_concept = requires(T c, U u) {
  c.preamble();
  c.heading(u);
  c.subheading(u);
  c.body(u);
  c.postamble();
};
// -------------------------------------------
template <typename T>
concept Builder = builder_concept<T, std::string_view>;
// -------------------------------------------
template <Builder DocBuilder> 
#else
template <typename DocBuilder> 
#endif
class EventLogParser {
public:
  EventLogParser() = default;
  using product = typename DocBuilder::product_t;

  product construct(std::string_view filename) {
    std::ifstream logfile{filename.data()};
    if (!logfile) {
      std::cerr << "can't open output file \"" << filename << "\"\n";
      return {};
    }

    builder.preamble();

    while (!logfile.eof()) {

      std::string entry{};
      std::string date{};
      std::string text{};

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
