/// planar_graph.h

#pragma once

#include "../basic/graph.h"

namespace PlanarGraphColoring {

class PlanarGraph : public Graph {
public:
  PlanarGraph() = default;
  PlanarGraph(const PlanarGraph& rhs) : Graph(rhs) {}
  PlanarGraph(PlanarGraph&& rhs) : Graph(std::move(rhs)) {}
  PlanarGraph& operator=(const PlanarGraph& rhs);
  PlanarGraph& operator=(PlanarGraph&& rhs);
  PlanarGraph(const std::vector<std::vector<size_t>>& edges);
  virtual void show(std::ostream& cout) const override;
  PlanarGraph(const size_t n, const std::vector<std::vector<size_t>>& edges);
};/// class PlanarGraph

}/// namespace PlanarGraphColoring
