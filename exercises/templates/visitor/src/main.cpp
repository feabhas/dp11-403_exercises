// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <array>
#include <iostream>
#include <memory>
#include <string>

class ElementA;
class ElementB;

// The visitor takes the instance reference as input, and implements the goal
// through double dispatch.
class Visitor {
public:
  virtual void visit(const ElementA *element) const = 0;
  virtual void visit(const ElementB *element) const = 0;
};

class Element {
public:
  virtual ~Element() = default;
  virtual void Accept(Visitor& visitor) const = 0;
};

class ElementA : public Element {
public:
  void Accept(Visitor& visitor) const override {
    visitor.visit(this);
  }
  std::string featureA() const { return "ElementA"; }
};

class ElementB : public Element {
public:
  void Accept(Visitor& visitor) const override {
    visitor.visit(this);
  }
  std::string featureB() const { return "ElementB"; }
};

class Visitor1 : public Visitor {
public:
  void visit(const ElementA *element) const override {
    std::cout << element->featureA() << str;
  }

  void visit(const ElementB *element) const override {
    std::cout << element->featureB() << str;
  }

private:
  constexpr static const char *str = " + Visitor1\n";
};

class Visitor2 : public Visitor {
public:
  void visit(const ElementA *element) const override {
    std::cout << element->featureA() << str;
  }
  void visit(const ElementB *element) const override {
    std::cout << element->featureB() << str;
  }

private:
  constexpr static const char *str = " + Visitor2\n";
};

int main() {
  ElementA ea{};
  ElementB eb{};

  std::array<Element*, 2> elements = {
      &ea, &eb};

  Visitor1 visitor1{};

  for (auto comp : elements) {
    comp->Accept(visitor1);
  }

  std::cout << "=============================\n";
  Visitor2 visitor2 {};
  for (auto comp : elements) {
    comp->Accept(visitor2);
  }
}
