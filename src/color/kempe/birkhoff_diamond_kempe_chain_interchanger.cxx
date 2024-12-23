/// birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../birkhoff_diamond_color_judger.h"
#include "../../subgraph/color_inducer.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const ColorResult& table, ColorResult* colorings_if, ColorResult* colorings_else) {
  /// assuming: there is a coloring on ring
  ///           to specify this coloring is on the boundary and cannot be extended to the interior of the ring directly thus need kempe chain interchange
  /// assuming: vertex_pair are nonadjacent on the boundary          
  ///           but may be connected by a kempe chain on the boundary (this situation shall be excluded)
  /// if there exists a kempe chain of vertex_pair return colorings_if
  /// otherwise return colorings_else
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair colorings_if colorings_else)
  INFO_OBJ(coloring)
  INFO_PAIR(vertex_pair)
  /// 0. if there exists a kempe chain of vertex_pair
  //     splitting the boundary into 2 parts
    /// 0.0 if vertex_pair have distinct colors
    /// 0.1 else vertex_pair have the same color
  DEBUG << "0. if:\n";
  bool res_if = this->run(ring, coloring, vertex_pair, id<size_t>(COLORS), table, colorings_if);
  //if (!res_if) return false;
  DEBUG_OBJ(*colorings_if)
  /// 1. else vertex_pair cannot be connected by a kempe chain
  ///    there must exist a kempe chain of separating_vertex_pair 
  ///    splitting the boundary into 2 parts with vertex_pair in each of them
  ///    PARTICULARLY this kempe chain must go to exterior of the ring at separating_vertex_pair
  ///    while this kempe chain may connect other vertices on the boundary
  ///    PARTICULARLY this kempe chain must not connect vertex_pair 
  ///    which shall be checked afterward
  DEBUG << "1. else:\n";
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  bool res_else = false;
  for (const auto& separating_vertex_pair : ring.getBoundarySeparatedVertexPairs(vertex_pair)) {
    /// 1.0 if separating_vertex_pair have distinct colors
    /// 1.1 else separating_vertex_pair have the same color
    DEBUG << "for ";
    DEBUG_PAIR(separating_vertex_pair)
    const size_t c = coloring.get(vertex_pair.first);
    const size_t d = coloring.get(vertex_pair.second);
    VI unused_colors;
    diff<size_t>(id<size_t>(COLORS), {c, d}, &unused_colors);
    if (this->run(ring, coloring, separating_vertex_pair, unused_colors, table, colorings_else)) {
      res_else = true;
      break;
    }/// if
  }/// for
  DEBUG_OBJ(*colorings_else)
  INFO_2VAR(res_if, res_else)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair colorings_if colorings_else)
  return res_if && res_else;
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const VI& unused_colors, const ColorResult& table, ColorResult* colorings) { 
  /// TODO: consider argument unused_colors is reasonable or not
  /// WARNING: most probably unreasonable
  /// WARNING: argument unused_colors is unnecessary, and afterward verification is needed
  /// TODO: both of colorings_if colorings_else may have duplicate
  /// TODO: dfs is needed for both colorings_if colorings_else, once a judger.valid coloring is found return instantly
  /// assuming: there exists a kempe chain of vertex_pair
  ///           but may not split the boundary into 2 parts
  /// RETURN: return colorings instantly once interchange a valid coloring
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair unused_colors colorings)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  DEBUG_VEC(unused_colors)
  const size_t c = coloring.get(vertex_pair.first);
  const size_t d = coloring.get(vertex_pair.second);
  if (c == d) {
    /// 0. vertex_pair have the same color
    DEBUG << "0. c==d\n";
    for (const auto unused_color : unused_colors) {
    //for (size_t color = 0; color < COLORS; ++color) {
      if (unused_color == c) continue;
      DEBUG << "for ";
      DEBUG_VAR(unused_color)
      this->run(ring, coloring, vertex_pair, std::pair<size_t, size_t>({c, unused_color}), table, colorings);
    }/// for
  } else {
    /// 1. vertex_pair have distinct colors
    DEBUG << "1. c!=d\n";
    this->run(ring, coloring, vertex_pair, std::pair<size_t, size_t>({c, d}), table, colorings);
  }/// else c != d
  DEBUG_OBJ(*colorings)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair unused_colors colorings)
  return !colorings->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run 

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, const ColorResult& table, ColorResult* colorings) {
  /// assuming: there exists a kempe chain of vertex_pair with color_pair
  ///           but this kempe chain may not split the boundary into 2 parts
  /// RETURN: return colorings instantly once interchange a valid coloring
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair color_pair colorings)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  DEBUG_PAIR(color_pair)
  ColorInducer inducer;
  KempeChain chain;
  inducer.run(ring, coloring, vertex_pair, color_pair, &chain);
  DEBUG_OBJ(chain)
  bool res = true;
  if (chain.size() < 2) {
    /// 0. if the kempe chain cannot split the boundary 
    DEBUG << "if chain size < 2\n";
    res = false;
  } else {
    /// 1. else the kempe chain can split the boundary
    ///    call kempe chain interchange
    DEBUG << "else chain size >= 2\n";
    res = false;
    for (const auto& separated_vertex_pair : chain.getSeparatedVertexPairs(ring.boundarySize())) {
      DEBUG << "for ";
      DEBUG_PAIR(separated_vertex_pair)
      const size_t c = coloring.get(separated_vertex_pair.first);
      const size_t d = coloring.get(separated_vertex_pair.second);
      if (c == d) {
        /// 1.0 if separated_vertex_pair have the same color
        DEBUG << "1.0 c==d\n";
        std::vector<size_t> unused_colors;
        diff<size_t>(id<size_t>(COLORS), {c, color_pair.first, color_pair.second}, &unused_colors);
        for (const auto unused_color : unused_colors) {
          DEBUG << "  for ";
          DEBUG_VAR(unused_color)
          if (this->interchange(ring, coloring, separated_vertex_pair, {c, unused_color}, table, colorings)) {
            res = true;
            break;
          }/// if
        }/// for unused_color
      } else {
        /// 1.1 else separated_vertex_pair have distinct colors
        DEBUG << "1.1 c!=d\n";
        res = this->interchange(ring, coloring, separated_vertex_pair, {c, d}, table, colorings);
      }/// else c != d
      if (res) break;
    }/// for separated_vertex_pair
  }/// else chain.size() >= 2
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair color_pair colorings)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::interchange(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, const ColorResult& table, ColorResult* colorings) {
  /// assuming: vertex_pair is separated by another kempe chain
  /// interchange the kempe chain induced by vertex_pair with color_pair
  /// RETURN: return colorings instantly once interchange a valid coloring
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::interchange ring coloring vertex_pair color_pair colorings)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  DEBUG_PAIR(color_pair)
  KempeChain chain;
  ColorInducer inducer;
  inducer.run(ring, coloring, vertex_pair, color_pair, &chain);
  DEBUG << "chain size must be 2!\n";
  DEBUG_OBJ(chain)
  bool res = false;
  res = res || this->interchange(coloring, chain.getConst(0), color_pair, table, colorings);
  res = res || this->interchange(coloring, chain.getConst(1), color_pair, table, colorings);
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::interchange ring coloring vertex_pair color_pair colorings)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::interchange

bool BirkhoffDiamondKempeChainInterchanger::interchange(const ColorRepresentation& coloring, const VI& chain, const II& color_pair, const ColorResult& table, ColorResult* colorings) {
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::interchange)
  NaiveColorRepresentation color(coloring.getVector());
  color.inverse(chain, color_pair);
  DEBUG_OBJ(color)
  BirkhoffDiamond diamond;
  const size_t index = table.find(color.getVector(), diamond.boundarySize());/// index must != -1
  auto found_ptr = table.getConst(index);
  DEBUG << "found_ptr:\n";
  DEBUG_OBJ(*found_ptr)
  BirkhoffDiamondColorJudger judger;
  const bool res = judger.isValid(*found_ptr);
  if (res) {
    DEBUG << "valid interchange!\n";
    colorings->append(color);
  } else {
    DEBUG << "invalid interchange!\n";
  }
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::interchange)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::interchange

}/// namespace PlanarGraphColoring
