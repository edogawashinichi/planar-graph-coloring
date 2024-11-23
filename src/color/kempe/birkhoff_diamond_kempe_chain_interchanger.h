/// birkhoff_diamond_kempe_chain_interchanger.h

#pragma once

#include "kempe_chain_interchanger.h"
#include "../../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondKempeChainInterchanger : public KempeChainInterchanger {
public:
  virtual bool run(const PlanarGraph& birkhoff_diamond, const ColorRepresentative& lhs, ColorResult* rhs) override;
};/// class BirkhoffDiamondKempeChainInterchanger

}/// namespace PlanarGraphColoring
