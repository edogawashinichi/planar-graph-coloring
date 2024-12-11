/// planar_graph.cxx

#include "planar_graph.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

PlanarGraph& PlanarGraph::operator=(const PlanarGraph& rhs) {
  /// TODO: if this==&rhs
  Graph::operator=(rhs);
  return *this;
}/// assignment deepcopy
PlanarGraph& PlanarGraph::operator=(PlanarGraph&& rhs) {
  Graph::operator=(std::move(rhs));
  return *this;
}/// assignment movecopy

PlanarGraph::PlanarGraph(const std::vector<std::vector<size_t>>& edges) : Graph(edges) {
}/// PlanarGraph::PlanarGraph

PlanarGraph::PlanarGraph(const size_t n, const std::vector<std::vector<size_t>>& edges) : Graph(n, edges) {
}/// PlanarGraph::PlanarGraph

void PlanarGraph::show() const {
  TEST_INFO
  const bool is_planar = Graph::isPlanarGraph();
  INFO_VAR(is_planar)
  Graph::show();
}/// PlanarGraph::show

}/// namespace PlanarGraphColoring
