/// johnson_trotter.h

#pragma once

#include "permutator.h"
#include "../../basic/notation.h"

namespace PlanarGraphColoring {

class JohnsonTrotter : public Permutator {
public:
  /* all permutations not in dictionary order */
  virtual VVI run(const size_t n) override;
  /* all even permutations */
  VVI runEven(const size_t n);
protected:
  VVI run(const size_t n, const bool even_only);
  /* flip each direction[i] with a[i] greater than value */
  void flipGreater(const VI& a, const size_t value, VI* direction);
  /* whether a[index] is mobile : not blocked by greater value or boundary */
  bool mobile(const VI& a, const VI& direction, const size_t index);
  /* mobile a[i] with max value */
  int maxMobileIndex(const VI& a, const VI& direction);
};/// class JohnsonTrotter

}/// namespace PlanarGraphColoring
