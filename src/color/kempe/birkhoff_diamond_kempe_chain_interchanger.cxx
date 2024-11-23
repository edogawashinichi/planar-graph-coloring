/// birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondKempeChainInterchanger::run(const PlanarGraph& graph, const ColorRepresentative& lhs, ColorResult* rhs) {
  DEBUG_START(BirkhoffDiamondChainInterchanger::run)
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(graph);
  for (const auto& pair : birkhoff_diamond.getBNV()) {
    const size_t u = pair.first;
    const size_t v = pair.second;
    const size_t uc = lhs.get(u);
    const size_t vc = lhs.get(v);
    DEBUG_2VAR(u, v)
    DEBUG_2VAR(uc, vc)
    std::vector<size_t> rest_colors;
    diff<size_t>(id<size_t>(COLORS), std::vector<size_t>({uc, vc}), &rest_colors);
    /// 0. if exist u-v kempe-chain
    
    /// 1. otherwise
  }/// for
  DEBUG_END(BirkhoffDiamondChainInterchanger::run)
  return !rhs->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run

}/// namespace PlanarGraphColoring
