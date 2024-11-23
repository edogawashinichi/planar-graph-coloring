/// structure.h

#pragma once

#include <cstddef>

namespace PlanarGraphColoring {

class Structure {
public:
  virtual void show() const = 0;
  virtual void show(const size_t n) const = 0;
};/// class Structure

}/// namespace PlanarGraphColoring
