// HTMLBuilder.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef HTML_BUILDERS_H
#define HTML_BUILDERS_H

#include <sstream>
#include <string>

#include "I_DocBuilder.h"

class HTMLBuilder : public I_DocBuilder {
public:
  std::string getProduct();

protected:
  void preamble() override;
  void heading(std::string_view str) override;
  void subheading(std::string_view str) override;
  void body(std::string_view str) override;
  void postamble() override;

private:
  std::stringstream product{};
};

#endif // HTML_BUILDERS_H
