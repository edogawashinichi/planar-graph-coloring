/// color_transformer.h

#pragma once

#include "color_representation.h"

namespace PlanarGraphColoring {

class ColorTransformer {
public:
  void transformByVertexSymmetry(const std::vector<size_t>& vertex_transformation, const ColorRepresentation& lhs, ColorRepresentation* rhs);
  void transformByColorSymmetry(const std::vector<size_t>& color_transformation, const ColorRepresentation& lhs, ColorRepresentation* rhs);
  void inverseVertexSymmetry(const std::vector<size_t>& input, std::vector<size_t>* output);
  void inverseColorSymmetry(const std::vector<size_t>& input, std::vector<size_t>* output);
};/// class ColorTransformer

}/// namespace PlanarGraphColoring
