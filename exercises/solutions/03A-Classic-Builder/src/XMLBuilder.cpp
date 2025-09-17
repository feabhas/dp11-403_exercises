// XMLBuilder.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "XMLBuilder.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

using std::string;
using std::stringstream;

string XMLBuilder::getProduct() { return product.str(); }

void XMLBuilder::preamble() {
  product << R"(<?xml version="1.0"?>)" << '\n';
  product << R"(<log>)" << '\n';
}

void XMLBuilder::heading(std::string_view str) {
  product << R"(<entry>)";
  product << str.data();
  product << R"(</entry>)";
  product << '\n';
}

void XMLBuilder::subheading(std::string_view str) {
  product << R"(<dateTime>)";
  product << str.data();
  product << R"(</dateTime>)";
  product << '\n';
}

void XMLBuilder::body(std::string_view str) {
  product << R"(<text>)";
  product << str.data();
  product << R"(</text>)";
  product << '\n';
}

void XMLBuilder::postamble() { product << R"(</log>)" << '\n'; }
