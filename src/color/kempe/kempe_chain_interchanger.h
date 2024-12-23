/// kempeChainInterchanger.h

#pragma once

#include "kempe_chain.h"
#include "../color_representation.h"
#include "../color_result.h"
#include "../../topology/ring.h"

/// TODO: reason kempe chain interchanger for each coloring in colorings_if and colorings_else

namespace PlanarGraphColoring {

class KempeChainInterchanger {
public:
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const ColorResult& table, ColorResult* colorings_if, ColorResult* colorings_else) = 0;
protected:
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const VI& unused_colors, const ColorResult& table, ColorResult* colorings) = 0;
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, const ColorResult& table, ColorResult* colorings) = 0;
  virtual bool interchange(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& colr_pair, const ColorResult& table, ColorResult* colorings) = 0;
  virtual bool interchange(const ColorRepresentation& coloring, const VI& chain, const II& color_pair, const ColorResult& table, ColorResult* colorings) = 0;
};/// class KempeChainInterchanger

}/// namespace PlanarGraphColoring
