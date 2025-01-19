/// combinator.h

#pragma once

#include "../basic/notation.h"

namespace PlanarGraphColoring {

class Combinator {
public:
  /* all combinations choosing k from n */
  virtual VVI run(const size_t n, const size_t k) = 0;
};/// class Combinator

}/// namespace PlanarGraphColoring
