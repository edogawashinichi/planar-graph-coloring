/// color_inducer.h

#pragma once

#include "vertex_inducer.h"
#include "../color/color_representation.h"
#include "../topology/ring.h"
#include "../color/kempe/kempe_chain.h"
/// TODO: kempe_chain.h

namespace PlanarGraphColoring {

class ColorInducer : public VertexInducer {
public:
  void run(const Graph& lhs, const ColorRepresentation& coloring, const std::vector<size_t>& colors, Graph* rhs);
  void run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, KempeChain* chain);
};/// class ColorInducer

}/// namespace PlanarGraphColoring
