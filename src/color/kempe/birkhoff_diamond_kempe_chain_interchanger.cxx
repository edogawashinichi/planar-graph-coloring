/// birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../birkhoff_diamond_color_judger.h"
#include "../../subgraph/color_inducer.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondKempeChainInterchanger::interchange(const ColorRepresentation& coloring, const ColorResult& table, const VI& chain, const II& color_pair, ColorRepresentation* interchange_coloring) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::interchange coloring table chain color_pair interchange_coloring)
  DEBUG_OBJ(coloring)
  DEBUG_VEC(chain)
  DEBUG_PAIR(color_pair)
  NaiveColorRepresentation inversed_coloring(coloring.getVector());
  inversed_coloring.inverse(chain, color_pair);
  DEBUG_OBJ(inversed_coloring)
  BirkhoffDiamond diamond;
  auto table_ptr = table.findConstPtr(inversed_coloring.getVector(), diamond.boundarySize());
  DEBUG_OBJ(*table_ptr)
  BirkhoffDiamondColorJudger judger;
  const bool res = judger.isValid(*table_ptr);
  if (res) {
    auto lhs = dynamic_cast<NaiveColorRepresentation*>(interchange_coloring);
    //*lhs = std::move(inversed_coloring);
    *lhs = *(dynamic_cast<const NaiveColorRepresentation*>(table_ptr));
  }
  DEBUG_FLAG_OBJ(res, *interchange_coloring)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::interchange coloring table chain color_pair interchange_coloring)
  return res;
}///BirkhoffDiamondKempeChainInterchanger::interchange

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const KempeChainConnector& separating_connector, const KempeChainConnector& separated_connector, ColorRepresentation* interchange_coloring) {
  /// assuming: separating_connector.vertex_pair_ don't overlap with separated_connector.vertex_pair_
  /// assuming: separating_connector.color_pair_ don't overlap with separated_connector.color_pair_
  DEBUG_START(BirkhoffDiamondChainInterchanger::run ring coloring table separating_connector separated_connector interchange_coloring)
  DEBUG_OBJ(separating_connector)
  DEBUG_OBJ(separated_connector)
  bool res = true;
  ColorInducer inducer;
  KempeChain separating_chain;
  inducer.run(ring, coloring, separating_connector.vertex_pair_, separating_connector.color_pair_, &separating_chain);
  res = res && (separating_chain.size() == 2);
  KempeChain separated_chain;
  inducer.run(ring, coloring, separated_connector.vertex_pair_, separated_connector.color_pair_, &separated_chain);
  res = res && (separated_chain.size() == 2);
  if (res) {
    res = (this->interchange(coloring, table, separated_chain.getConst(0), separated_connector.color_pair_, interchange_coloring));
    res = res || (this->interchange(coloring, table, separated_chain.getConst(1), separated_connector.color_pair_, interchange_coloring));
  }/// if
  DEBUG_FLAG_OBJ(res, *interchange_coloring)
  DEBUG_END(BirkhoffDiamondChainInterchanger::run ring coloring table separating_connector separated_connector interchange_coloring)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::getColorPairs(const ColorRepresentation& coloring, const VI& used_colors, const II& vertex_pair, VII* color_pairs) {
  VERBOSE_START(BirkhoffDiamondKempeChainInterchanger::getColorPairs)
  const size_t c = coloring.get(vertex_pair.first);
  const size_t d = coloring.get(vertex_pair.second);
  if (cap<size_t>({c, d}, used_colors)) {
    ;
  } else if (c != d) {
    color_pairs->emplace_back(std::pair<size_t, size_t>({c, d}));
  } else {
    VI tmp_colors(used_colors);
    tmp_colors.emplace_back(c);
    VI unused_colors;
    diff<size_t>(id<size_t>(COLORS), tmp_colors, &unused_colors);
    for (const auto& color : unused_colors) {
      color_pairs->emplace_back(std::pair<size_t, size_t>({c, color}));
    }/// for
  }/// else c == d
  VERBOSE_END(BirkhoffDiamondKempeChainInterchanger::getColorPairs)
  return !color_pairs->empty();
}/// BirkhoffDiamondKempeChainInterchanger::getColorPairs

bool BirkhoffDiamondKempeChainInterchanger::runSeparating(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separating_info) {
  /// TODO: merge runSeparating and runSeparated with macro
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::runSeparating ring coloring table vertex_pair separating_info)
  DEBUG_PAIR(vertex_pair)
  bool res = false;
  VII color_pairs;
  this->getColorPairs(coloring, {}, vertex_pair, &color_pairs);
  for (const auto& color_pair : color_pairs) {
    KempeChainConnector separating_connector(vertex_pair, color_pair);
    for (const auto& separated_vertex_pair : ring.getBoundarySeparatedVertexPairs(vertex_pair)) {
      VII separated_color_pairs;
      this->getColorPairs(coloring, {color_pair.first, color_pair.second}, separated_vertex_pair, &separated_color_pairs);
      for (const auto& separated_color_pair : separated_color_pairs) {
        KempeChainConnector separated_connector(separated_vertex_pair, separated_color_pair);
        if (this->run(ring, coloring, table, separating_connector, separated_connector, &(separating_info->interchange_))) {
        DEBUG << "this run ok\n";
        res = true;
        separating_info->color_pair_ = color_pair;
        separating_info->dual_ = separated_connector;
        break;
        }/// if
      }/// for separated_color_pair
      if (res) break;
    }/// for separated_vertex_pair
    if (res) break;
  }/// for color_pair
  DEBUG_FLAG_OBJ(res, *separating_info)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::runSeparating ring coloring table vertex_pair separating_info)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::runSeparating

bool BirkhoffDiamondKempeChainInterchanger::runSeparated(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainInfo* separated_info) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::runSeparated ring coloring table vertex_pair separated_info)
  DEBUG_PAIR(vertex_pair)
  bool res = false;
  VII color_pairs;
  this->getColorPairs(coloring, {}, vertex_pair, &color_pairs);
  for (const auto& color_pair : color_pairs) {
    KempeChainConnector separated_connector(vertex_pair, color_pair);
    for (const auto& separating_vertex_pair : ring.getBoundarySeparatedVertexPairs(vertex_pair)) {
      VII separating_color_pairs;
      this->getColorPairs(coloring, {color_pair.first, color_pair.second}, separating_vertex_pair, &separating_color_pairs);
      for (const auto& separating_color_pair : separating_color_pairs) {
        KempeChainConnector separating_connector(separating_vertex_pair, separating_color_pair);
        if (this->run(ring, coloring, table, separating_connector, separated_connector, &(separated_info->interchange_))) {
        DEBUG << "this run ok\n";
        res = true;
        separated_info->color_pair_ = color_pair;
        separated_info->dual_ = separating_connector;
        break;
        }/// if
      }/// for separating_color_pair
      if (res) break;
    }/// for separating_vertex_pair
    if (res) break;
  }/// for color_pair
  DEBUG_FLAG_OBJ(res, *separated_info)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::runSeparated ring coloring table vertex_pair separated_info)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::runSeparated

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, const II& vertex_pair, KempeChainResult* result) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring table vertex_pair result)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  result->vertex_pair_ = vertex_pair;
  const bool res_separating = this->runSeparating(ring, coloring, table, vertex_pair, &(result->separating_));
  const bool res_separated = this->runSeparated(ring, coloring, table, vertex_pair, &(result->separated_));
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  DEBUG_FLAG_OBJ(res_separating, result->separating_)
  DEBUG_FLAG_OBJ(res_separated, result->separated_)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring table vertex_pair result)
  return res_separating && res_separated;
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const ColorResult& table, KempeChainResult* result) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring table result)
  bool res = false;
  for (const auto& vertex_pair : ring.getBoundaryNonadjacentVertexPairs()) {
    if (!this->run(ring, coloring, table, vertex_pair, result)) continue;
    res = true;
    break;
  }/// for
  DEBUG_OBJ(coloring)
  DEBUG_FLAG_OBJ(res, *result)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring table result)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::run

}/// namespace PlanarGraphColoring
