/// permutator.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

class Permutator {
public:
  /* generate all permutations of {0, 1, ..., n-1} */
  virtual std::vector<std::vector<size_t>> run(const size_t n) = 0;
};/// class Permutator

}/// namespace PlanarGraphColoring
