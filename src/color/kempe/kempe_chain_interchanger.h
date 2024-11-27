/// kempeChainInterchanger.h

#pragma once

#include "../color_representation.h"
#include "../color_result.h"
#include "../../topology/ring.h"

namespace PlanarGraphColoring {

class KempeChainInterchanger {
public:
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, ColorResult* colorings) = 0;
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings) = 0;
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const II& kempe_vertex_pair, const II& separated_vertex_pair, ColorResult* colorings) = 0;
};/// class KempeChainInterchanger

}/// namespace PlanarGraphColoring
