/// birkhoff_diamond_kempe_chain_interchanger.h

#pragma once

#include "kempe_chain_interchanger.h"
#include "../../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondKempeChainInterchanger : public KempeChainInterchanger {
public:
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, ColorResult* colorings) override;
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings) override;
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& kempe_vertex_pair, const II& separated_vertex_pair, ColorResult* colorings) override;
};/// class BirkhoffDiamondKempeChainInterchanger

}/// namespace PlanarGraphColoring
