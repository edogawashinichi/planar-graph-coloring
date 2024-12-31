/// birkhoff_diamond_kempe_chain_interchanger.h

#pragma once

#include "kempe_chain_interchanger.h"
#include "../../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondKempeChainInterchanger : public KempeChainInterchanger {
public:
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const ColorResult& table, KempeChainResult* result) override;
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainResult* result) override;
  virtual bool runSeparating(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separating_info) override;
  virtual bool runSeparated(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separated_info) override;
  virtual bool run(const Ring& birkhoff_diamond, const ColorRepresentation& coloring, const ColorResult& table, const KempeChainConnector& separating_connector, const KempeChainConnector& separated_connector, ColorRepresentation* interchange_coloring) override;
  virtual bool getColorPairs(const ColorRepresentation& coloring, const VI& used_colors, const II& vertex_pair, VII* color_pairs) override;
  virtual bool interchange(const ColorRepresentation& coloring, const ColorResult& table, const VI& chain, const II& color_pair, ColorRepresentation* interchange_coloring) override;
};/// class BirkhoffDiamondKempeChainInterchanger

}/// namespace PlanarGraphColoring
