/// ring.cxx

#include "ring.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

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
