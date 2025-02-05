/// structure.h

#pragma once

#include <cstddef>
#include <ostream>

namespace PlanarGraphColoring {

class Structure {
public:
  virtual void show(std::ostream& cout) const = 0;
  virtual void show(std::ostream& cout, const size_t n) const = 0;
};/// class Structure

}/// namespace PlanarGraphColoring
