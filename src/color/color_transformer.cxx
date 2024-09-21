/// color_transformer.cxx

#include "color_transformer.h"

namespace PlanarGraphColoring {

void ColorTransformer::transformByVertexSymmetry(const std::vector<int>& vertex_symmetry, const ColorRepresentation& lhs, ColorRepresentation* rhs) {
  for (size_t i = 0; i < lhs.size(); ++i) {
    const size_t j = vertex_symmetry[i];
    rhs->set(j, lhs.get(i));
  }
}/// ColorTransformer::transformByVertexSymmetry

void ColorTransformer::transformByColorSymmetry(const std::vector<int>& color_symmetry, const ColorRepresentation& lhs, ColorRepresentation* rhs) {
  for (size_t i = 0; i < lhs.size(); ++i) {
    const int c = color_symmetry[lhs.get(i)];
    rhs->set(i, c);
  }
}/// ColorTransformer::transformByColorSymmetry

}/// namespace PlanarGraphColoring
