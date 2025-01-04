/// color_transformer.cxx

#include "color_transformer.h"
#include "../algebra/symmetry.h"
#include "../basic/math.h"

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
  VERBOSE_START(ColorTransformer::inverseColorSymmetry)
  output->resize(input.size());/// default value 0
  *output = id<size_t>(input.size());
  VERBOSE_VEC(*output)
  Transformation t(input);
  *output = t.inverse();/// deepcopy
  VERBOSE_END(ColorTransformer::inverseColorSymmetry)
}/// ColorTransformer::inverseColorSymmetry

}/// namespace PlanarGraphColoring
