/// birkhoff_diamond.cxx

#include "birkhoff_diamond.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

BirkhoffDiamond::BirkhoffDiamond() {
  k_ = 6; /// boundary size
  n_ = 6 + 4; /// total
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {0, 5}, {0, 6},
    {1, 2}, {1, 6}, {1, 7},
    {2, 3}, {2, 7}, {2, 8},
    {3, 4}, {3, 8},
    {4, 5}, {4, 8}, {4, 9},
    {5, 6}, {5, 9},
    {6, 7}, {6, 9},
    {7, 8}, {7, 9},
    {8, 9}
  };
  for (const auto& edge : edges) {
    const size_t u = edge.front();
    const size_t v = edge.back();
    neighbors_[u].emplace_back(v);
    neighbors_[v].emplace_back(u);
    if (u < k_ && v < u) {
      boundary_backward_neighbors_[u].emplace_back(v);
    }
    if (v < k_ && u < v) {
      boundary_backward_neighbors_[v].emplace_back(u);
    }
    if (u >= k_ && v < u) {
      interior_backward_neighbors_[u].emplace_back(v);
    }
    if (v >= k_ && u < v) {
      interior_backward_neighbors_[v].emplace_back(u);
    }
  }

  std::vector<std::vector<size_t>> mappers = {
    {0, 5, 4, 3, 2, 1}, /* vertical flip */
    {3, 2, 1, 0, 5, 4}, /* horizontal flip */
    {3, 4, 5, 0, 1, 2}, /* (counter)clockwise 180 degrees rotation */
  };
  vertex_symmetry_.set(mappers);
}/// BirkhoffDiamond::BirkhoffDiamond

void BirkhoffDiamond::show() const {
  if (!PGC__DEBUG_MODE) return;
  PGC__SHOW_ENDL("boundary backward neighbors:")
  PGC__SHOW_MIVI__(boundary_backward_neighbors_)
  PGC__SHOW_ENDL("interior backward neighbors:")
  PGC__SHOW_MIVI__(interior_backward_neighbors_)
  PGC__SHOW_ENDL("vertex symmetry:")
  vertex_symmetry_.show();
  Ring::show();
}/// BirkhoffDiamond::show

/*
/// TODO: this function shall be owened to class Judger
bool BirkhoffDiamond::isomorphismColoring(const ColorResult& lhs, const ColorResult& rhs) const {
  return true;
}/// BirkhoffDiamond::isomorphismColoring
*/

}/// namespace PlanarGraphColoring
