/// ring.cxx

#include "ring.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

const VII Ring::getBoundarySeparatedPairs(const size_t i, const size_t j) const {
  /// assuming: 0 <= i,j < k_
  VII res;
  for (size_t inter = (i + 1) % k_; inter != j; inter = (inter + 1) % k_) {
    for (size_t jnter = (j + 1) % k_; jnter != i; jnter = (jnter + 1) % k_) {
      res.emplace_back(std::pair<size_t, size_t>({inter, jnter}));
    }/// for jnter
  }/// for inter
  return res;
}/// Ring::getBoundarySeparatedPairs

Ring::Ring(const size_t k, const size_t n, const std::vector<std::vector<size_t>>& edges) :
  PlanarGraph(n, edges), k_(k) {
}/// Ring::Ring

void Ring::show() const {
  TEST_INFO
  std::cout << "boundary size: " << k_ << "\n";
  std::cout << "interior size: " << interiorSize() << "\n";
  PlanarGraph::show();
}/// Ring::show

}/// PlanarGraphColoring
