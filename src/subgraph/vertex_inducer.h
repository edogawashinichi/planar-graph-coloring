/// vertex_inducer.h

#pragma once

#include "edge_inducer.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class VertexInducer : public EdgeInducer {
public:
  void run(const Graph& lhs, const VI& vertices, Graph* rhs);
};/// class VertexInducer

}/// namespace PlanarGraphColoring
