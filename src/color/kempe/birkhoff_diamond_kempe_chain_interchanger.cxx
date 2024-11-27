/// birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../birkhoff_diamond_color_judger.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& kempe_vertex_pair, const II& separated_vertex_pair, ColorResult* colorings) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring kempe_vertex_pair separated_vertex_pair colorings)
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(ring);
  auto naive = dynamic_cast<const NaiveColorRepresentation&>(coloring);
  BirkhoffDiamondColorJudger judger;
  {
    NaiveColorRepresentation anonym(naive);
    const size_t first = separated_vertex_pair.first;
    const size_t second = separated_vertex_pair.second;
    anonym.set(first, coloring.get(second));
    DEBUG_OBJ(anonym)
    if (judger.isBoundaryColoringValid(birkhoff_diamond, anonym)) {
      DEBUG << "valid!\n";
      colorings->append(anonym);
    } else {
      DEBUG << "invalid!\n";
    }
  }
  {
    NaiveColorRepresentation anonym(naive);
    const size_t first = separated_vertex_pair.first;
    const size_t second = separated_vertex_pair.second;
    anonym.set(second, coloring.get(first));
    DEBUG_OBJ(anonym)
    if (judger.isBoundaryColoringValid(birkhoff_diamond, anonym)) {
      DEBUG << "valid!\n";
      colorings->append(anonym);
    } else {
      DEBUG << "invalid!\n";
    }
  }
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring kempe_vertex_pair separated_vertex_pair colorings)
  return !colorings->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings) {
  return !colorings->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, ColorResult* colorings) {
  DEBUG_START(BirkhoffDiamondChainInterchanger::run)
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(ring);
  for (const auto& pair : birkhoff_diamond.getBNV()) {
    const size_t u = pair.first;
    const size_t v = pair.second;
    const size_t uc = coloring.get(u);
    const size_t vc = coloring.get(v);
    DEBUG_2VAR(u, v)
    DEBUG_2VAR(uc, vc)
    std::vector<size_t> rest_colors;
    diff<size_t>(id<size_t>(COLORS), std::vector<size_t>({uc, vc}), &rest_colors);
    /// 0. if exist u-v kempe-chain
    /// TODO
    /// 1. otherwise
  }/// for
  DEBUG_END(BirkhoffDiamondChainInterchanger::run)
  return !colorings->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run

}/// namespace PlanarGraphColoring
