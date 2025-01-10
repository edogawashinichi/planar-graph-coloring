/// permutation.h

#pragma once

#include "../basic/notation.h"

namespace PlanarGraphColoring {

class Permutation {
public:
  CLASS_5_FUNCTIONS(Permutation, f_)
  Permutation(const VI& a);
  void show() const;
  bool id() const;
  VVI getCycles() const;
protected:
  std::vector<size_t> f_;
};/// class Permutation

}/// namespace PlanarGraphColoring
