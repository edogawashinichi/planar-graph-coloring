/// planar_graph.h

#pragma once

#include "../basic/graph.h"

namespace PlanarGraphColoring {

class PlanarGraph : public Graph {
public:
  PlanarGraph() = default;
  PlanarGraph(const std::vector<std::vector<size_t>>& edges);
  PlanarGraph(const size_t n, const std::vector<std::vector<size_t>>& edges);
  void show() const;
  bool isPlanar() const;
};/// class PlanarGraph

}/// namespace PlanarGraphColoring
