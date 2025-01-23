/// permutation_transformer.h

#pragma once

#include "permutation.h"

namespace PlanarGraphColoring {

class PermutationTransformer {
public:
  inline Permutation run(const VI& permutation) {
    return Permutation(permutation);
  }/// run
  inline std::vector<Permutation> run(const VVI& permutations) {
    std::vector<Permutation> res(permutations.size(), Permutation());
    for (size_t i = 0; i < permutations.size(); ++i) {
      res[i] = std::move(Permutation(permutations[i]));
    }/// for
    return res;
  }/// run
};/// class PermutationTransformer

}/// namespace PlanarGraphColoring
