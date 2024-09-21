/// birkhoff_diamond_color_judger.h

#pragma once

#include "color_judger.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondColorJudger : public ColorJudger {
public:
  virtual bool isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) override;
  virtual bool isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) override;
  virtual bool isIsomorphismByKempeChainTransformation(const ColorRepresentation& lhs, const ColorRepresentation& rhs) override;
};/// class BirkhoffDiamondColorJudger

}/// namespace PlanrGraphColoring
