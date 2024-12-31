/// ring.cxx

#include "ring.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

const VII Ring::getBoundaryNonadjacentVertexPairs() const {
  /// WARNING: size_t loop penetration
  int k = static_cast<int>(k_);
  VII res;
  for (int i = 0; i <= k - 3; ++i) {
    const int ma = ((0 == i) ? k - 2 : k - 1);
    for (int j = i + 2; j <= ma; ++j) {
      res.emplace_back(std::pair<size_t, size_t>({i, j}));
    }/// for j
  }/// for i
  return res;
}/// Ring::getBoundaryNonadjacentVertexPairs

const VII Ring::getBoundarySeparatedVertexPairs(const II& vertex_pair) const {
  size_t x = vertex_pair.first;
  size_t y = vertex_pair.second;
  if (x > y) std::swap(x, y);
  return this->getBoundarySeparatedVertexPairs(x, y);
}/// Ring::getBoundarySeparatedVertexPairs

const VII Ring::getBoundarySeparatedVertexPairs(const size_t i, const size_t j) const {
  /// assuming: 0 <= i,j < k_
  VII res;
  for (size_t inter = (i + 1) % k_; inter != j; inter = (inter + 1) % k_) {
    for (size_t jnter = (j + 1) % k_; jnter != i; jnter = (jnter + 1) % k_) {
      res.emplace_back(std::pair<size_t, size_t>({inter, jnter}));
    }/// for jnter
  }/// for inter
  return res;
}/// Ring::getBoundarySeparatedVertexPairs

Ring& Ring::operator=(const Ring& rhs) {
  /// TODO: this==&rhs
  PlanarGraph::operator=(rhs);
  k_ = rhs.k_;
  return *this;
}/// assignment deepcopy
Ring& Ring::operator=(Ring&& rhs) {
  PlanarGraph::operator=(std::move(rhs));
  std::swap(k_, rhs.k_);
  return *this;
}/// assignment movecopy

Ring::Ring(const size_t k) {
  n_ = k_ = k;
  for (int i = 0; i < static_cast<int>(k); ++i) {
    Graph::addEdge(i, (i + 1) % k);
  }/// for
}/// Ring::Ring

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
