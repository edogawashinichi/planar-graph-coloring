/// color_inducer.cxx

#include "color_inducer.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void ColorInducer::run(const Graph& lhs, const ColorRepresentation& coloring, const std::vector<size_t>& colors, Graph* rhs) {
  const std::vector<size_t> vertices(coloring.getVertices(colors));
  VertexInducer::run(lhs, vertices, rhs);
}/// ColorInducer::run

}/// namespace PlanarGraphColoring
