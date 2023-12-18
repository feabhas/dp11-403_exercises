// HTMLBuilder.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "HTMLBuilder.h"
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

using std::string;
using std::stringstream;

string HTMLBuilder::getProduct() { return product.str(); }

void HTMLBuilder::preamble() {
  product << R"(<!DOCTYPE html>)" << '\n';
  product << R"(<html>)" << '\n';
}

void HTMLBuilder::heading(std::string_view str) {
  product << R"(<h1>)";
  product << str.data();
  product << R"(</h1>)";
  product << '\n';
}

void HTMLBuilder::subheading(std::string_view str) {
  product << R"(<h2>)";
  product << str.data();
  product << R"(</h2>)";
  product << '\n';
}

void HTMLBuilder::body(std::string_view str) {
  product << R"(<p>)";
  product << str.data();
  product << R"(</p>)";
  product << '\n';
}

void HTMLBuilder::postamble() { product << R"(</html>)" << '\n'; }
