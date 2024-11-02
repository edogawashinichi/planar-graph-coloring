/// color_transformer.cxx

#include "color_transformer.h"
#include "../algebra/symmetry.h"

namespace PlanarGraphColoring {

void ColorTransformer::transformByVertexSymmetry(const std::vector<size_t>& vertex_symmetry, const ColorRepresentation& lhs, ColorRepresentation* rhs) {
  /// assuming vertex_symmetry.size() == lhs.size()
  for (size_t i = 0; i < lhs.size(); ++i) {
    const size_t j = vertex_symmetry[i];
    rhs->set(j, lhs.get(i));
  }
}/// ColorTransformer::transformByVertexSymmetry

void ColorTransformer::transformByColorSymmetry(const std::vector<size_t>& color_symmetry, const ColorRepresentation& lhs, ColorRepresentation* rhs) {
  /// assuming color(lhs).size == color_symmetry.size()
  for (size_t i = 0; i < lhs.size(); ++i) {
    const size_t c = color_symmetry[lhs.get(i)];
    rhs->set(i, c);
  }
}/// ColorTransformer::transformByColorSymmetry

void ColorTransformer::inverseVertexSymmetry(const std::vector<size_t>& input, std::vector<size_t>* output) {
  output->resize(input.size());
  Transformation t(input);
  *output = t.inverse();
}/// ColorTransformer::inverseVertexSymmetry

void ColorTransformer::inverseColorSymmetry(const std::vector<size_t>& input, std::vector<size_t>* output) {
  output->resize(input.size());
  Transformation t(input);
  *output = t.inverse();/// always deep-copy for any compiler
}/// ColorTransformer::inverseColorSymmetry

}/// namespace PlanarGraphColoring
