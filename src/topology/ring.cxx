/// ring.cxx

#include "ring.h"
#include <iostream>

namespace PlanarGraphColoring {

Ring::Ring(const size_t k, const size_t n, const std::vector<std::vector<int>>& edges) :
  Graph(n, edges), k_(k) {
}/// Ring::Ring

void Ring::show() const {
  std::cout << "boundary size: " << k_ << "\n";
  std::cout << "interior size: " << interiorSize() << "\n";
  Graph::show();
}/// Ring::show

}/// PlanarGraphColoring
