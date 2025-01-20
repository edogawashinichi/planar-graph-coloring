/// next_iter_permutator.h

#pragma once

#include "permutator.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

class NextIterPermutator : public Permutator {
public:
  /* all permutations in dictionary order */
  virtual VVI run(const size_t n) override;
  VI run(const size_t n, const size_t i);
  bool run(const VI& cur, VI* next);
protected:
  int ascendMaxIndex(const VI& a);
  size_t minAscendIndex(const VI& a, const size_t ascend_max_index);
};/// class NextIterPermutator

}/// namespace PlanarGraphColoring
