/// planar_graph.cxx

#include "planar_graph.h"

namespace PlanarGraphColoring {

PlanarGraph::PlanarGraph(const size_t n, const std::vector<std::vector<size_t>>& edges) : Graph(n, edges) {
}/// PlanarGraph::PlanarGraph

bool PlanarGraph::isPlanar() const {
  /// TODO
  return true;
}/// PlanarGraph::isPlanar

}/// namespace PlanarGraphColoring
