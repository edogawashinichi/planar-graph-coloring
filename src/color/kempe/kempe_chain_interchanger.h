/// kempeChainInterchanger.h

#pragma once

#include "kempe_chain.h"
#include "../color_representation.h"
#include "../color_result.h"
#include "../../topology/ring.h"

/// TODO: consider dynamic table by disjoint-set

namespace PlanarGraphColoring {

class KempeChainInterchanger {
public:
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, KempeChainResult* result) = 0;
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainResult* result) = 0;
  virtual bool runSeparating(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separating_info) = 0;
  virtual bool runSeparated(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separated_info) = 0;
  virtual bool run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const KempeChainConnector& separating_connector, const KempeChainConnector& separated_connector, ColorRepresentation* interchange_coloring) = 0;
  virtual bool getColorPairs(const ColorRepresentation& coloring, const VI& used_colors, const II& vertex_pair, VII* color_pairs) = 0;
  virtual bool interchange(const ColorRepresentation& coloring, const ColorResult& table, const VI& chain, const II& color_pair, ColorRepresentation* interchange_coloring) = 0;
};/// class KempeChainInterchanger

}/// namespace PlanarGraphColoring
