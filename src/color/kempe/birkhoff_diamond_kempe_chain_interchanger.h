/// birkhoff_diamond_kempe_chain_interchanger.h

#pragma once

#include "kempe_chain_interchanger.h"
#include "../../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondKempeChainInterchanger : public KempeChainInterchanger {
public:
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings_if, ColorResult* colorings_else) override;
protected:
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings) override;
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, ColorResult* colorings) override;
  virtual void interchange(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, ColorResult* colorings) override;
};/// class BirkhoffDiamondKempeChainInterchanger

}/// namespace PlanarGraphColoring
