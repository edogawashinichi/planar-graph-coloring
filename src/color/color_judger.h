/// color_judger.h

#pragma once

#include "color_representation.h"

namespace PlanarGraphColoring {

class ColorJudger {
public:
  virtual bool isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) = 0;
  virtual bool isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs, std::vector<size_t>* mapper) = 0;
  virtual bool isIsomorphismByVertexSymmetry(const std::vector<size_t>& lhs, const std::vector<size_t>& rhs, std::vector<size_t>* mapper) = 0;
  virtual bool isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) = 0;
  virtual bool isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs, std::vector<size_t>* mapper) = 0;
  virtual bool isIsomorphismByColorSymmetry(const std::vector<size_t>& lhs, const std::vector<size_t>& rhs, std::vector<size_t>* mapper) = 0;
  virtual bool isIsomorphismByKempeChainTransformation(const ColorRepresentation& lhs, const ColorRepresentation& rhs) = 0;
};/// class ColorJudger

}/// namespace PlanarGraphColoring
