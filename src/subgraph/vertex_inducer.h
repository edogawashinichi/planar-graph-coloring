/// vertex_inducer.h

/// TODO
/// graph --vertex_inducer--> graph

#pragma once

#include "../basic/graph.h"

namespace PlanarGraphColoring {

class VertexInducer {
public:
  void run(const Graph& lhs, const std::vector<size_t>& vertices, Graph* rhs);
};/// class VertexInducer

}/// namespace PlanarGraphColoring
