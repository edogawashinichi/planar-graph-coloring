/// color_triple.cxx

#include "color_triple.h"
#include "../naive_color_representation.h"

namespace PlanarGraphColoring {

void ColorTriple::show() const {
  TEST_INFO
  std::cout << "ColorTriple::show:\n";
  std::cout << "first_:\n";
  if (first_) {
    first_->show();
  } else {
    std::cout << "nullptr\n";
  }
  std::cout << "second_:\n";
  if (second_) {
    second_->show();
  } else {
    std::cout << "nullptr\n";
  }
  std::cout << "third_:\n";
  if (third_) {
    third_->show();
  } else {
    std::cout << "nullptr\n";
  }
}/// ColorTriple::show

ColorTriple::~ColorTriple() {
  this->free(first_);
  this->free(second_);
  this->free(third_);
}/// ColorTriple::~ColorTriple

void ColorTriple::set(const ColorRepresentation& first, const ColorRepresentation& second, const ColorRepresentation& third) {
  this->set(first_, first);
  this->set(second_, second);
  this->set(third_, third);
}/// ColorTriple::set

void ColorTriple::set(ColorRepresentation*& ptr, const ColorRepresentation& obj) { /// WARNING: reference of pointer
  /// TODO: get rid of NaiveColorRepresentation
  DEBUG_START(ColorTriple::set)
  if (ptr) {
    this->free(ptr);
  }
  /// ptr==nullptr
  ptr = new NaiveColorRepresentation(obj.getVector());
  DEBUG_END(ColorTriple::set)
}/// ColorTriple::set

void ColorTriple::free(ColorRepresentation* ptr) {
  if (ptr) {
    delete ptr;
    ptr = nullptr;
  }
}/// ColorTriple::free

}/// namespace PlanarGraphColoring
