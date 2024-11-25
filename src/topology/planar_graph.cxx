/// planar_graph.cxx

#include "planar_graph.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

PlanarGraph::PlanarGraph(const std::vector<std::vector<size_t>>& edges) : Graph(edges) {
}/// PlanarGraph::PlanarGraph

PlanarGraph::PlanarGraph(const size_t n, const std::vector<std::vector<size_t>>& edges) : Graph(n, edges) {
}/// PlanarGraph::PlanarGraph

void PlanarGraph::show() const {
  TEST_INFO
  const bool is_planar = this->isPlanar();
  INFO_VAR(is_planar)
  Graph::show();
}/// PlanarGraph::show

bool PlanarGraph::isPlanar() const {
  /// TODO
  return true;
}/// PlanarGraph::isPlanar

}/// namespace PlanarGraphColoring
