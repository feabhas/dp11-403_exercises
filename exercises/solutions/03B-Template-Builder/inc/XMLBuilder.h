// XMLBuilder.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef BUILDERS_H
#define BUILDERS_H

#include <sstream>
#include <string>

class XMLBuilder {
public:
  using product_t = std::string;
  product_t getProduct();
  void preamble();
  void heading(std::string_view str);
  void subheading(std::string_view str);
  void body(std::string_view str);
  void postamble();

private:
  std::stringstream product{};
};

#endif // BUILDERS_H
