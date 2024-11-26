/// edge_inducer.h

#pragma once

#include "../basic/graph.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class EdgeInducer {
public:
  void run(const Graph& lhs, const VII& edges, Graph* rhs);
};/// class EdgeInducer

}/// namespace PlanarGraphColoring
