/// interpreter.h

#pragma once

#include <ostream>

namespace PlanarGraphColoring {

class Interpreter {
public:
  virtual void show(std::ostream& cout) const = 0;
};/// class Interpreter

}/// namespace PlanarGraphColoring
