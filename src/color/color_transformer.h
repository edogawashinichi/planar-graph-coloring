/// color_transformer.h

#pragma once

#include "color_representation.h"

namespace PlanarGraphColoring {

class ColorTransformer {
public:
  void transformByVertexSymmetry(const std::vector<int>& vertex_transformation, const ColorRepresentation& lhs, ColorRepresentation* rhs);
  void transformByColorSymmetry(const std::vector<int>& color_transformation, const ColorRepresentation& lhs, ColorRepresentation* rhs);
};/// class ColorTransformer

}/// namespace PlanarGraphColoring
