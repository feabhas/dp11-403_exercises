// I_DocBuilder.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef I_BUILDER_H
#define I_BUILDER_H

#include <string_view>

class I_DocBuilder {
public:
  virtual void preamble() = 0;
  virtual void heading(std::string_view str) = 0;
  virtual void subheading(std::string_view str) = 0;
  virtual void body(std::string_view str) = 0;
  virtual void postamble() = 0;
  virtual ~I_DocBuilder() = default;
};

#endif // I_BUILDER_H
