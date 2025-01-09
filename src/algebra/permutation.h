/// permutation.h

#pragma once

#include "../basic/notation.h"

namespace PlanarGraphColoring {

class Permutation {
public:
  CLASS_5_FUNCTIONS(Permutation, f_)
  Permutation(const size_t i);
protected:
  std::vector<size_t> f_;
};/// class Permutation

}/// namespace PlanarGraphColoring
