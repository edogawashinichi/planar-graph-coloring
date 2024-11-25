/// color_inducer.h

#pragma once

#include "vertex_inducer.h"
#include "../color/color_representation.h"

namespace PlanarGraphColoring {

class ColorInducer : public VertexInducer {
public:
  void run(const Graph& lhs, const ColorRepresentation& coloring, const std::vector<size_t>& colors, Graph* rhs);
};/// class ColorInducer

}/// namespace PlanarGraphColoring
