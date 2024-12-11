/// birkhoff_diamond_kempe_chain_interchanger.cxx

#include "birkhoff_diamond_kempe_chain_interchanger.h"
#include "../naive_color_representation.h"
#include "../birkhoff_diamond_color_judger.h"
#include "../../subgraph/color_inducer.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings_if, ColorResult* colorings_else) {
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
  bool res_if = this->run(ring, coloring, vertex_pair, colorings_if);
  DEBUG_OBJ(*colorings_if)
  /// 1. else vertex_pair cannot be connected by a kempe chain
  ///    there must exist a kempe chain of separated_vertex_pair 
  ///    splitting the boundary into 2 parts with vertex_pair in each of them
  /// TODO: debug colorings_else
  DEBUG << "1. else:\n";
  bool res_else = false;
  for (const auto& separated_vertex_pair : ring.getBoundarySeparatedVertexPairs(vertex_pair)) {
    /// 1.0 if separated_vertex_pair have distinct colors
    /// 1.1 else separated_vertex_pair have the same color
    if (this->run(ring, coloring, separated_vertex_pair, colorings_else)) {
      res_else = true;
      break;
    }/// if
  }/// for
  DEBUG_OBJ(*colorings_else)
  INFO_2VAR(res_if, res_else)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair colorings_if colorings_else)
  return res_if || res_else;
}/// BirkhoffDiamondKempeChainInterchanger::run

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, ColorResult* colorings) { 
  /// assuming: there exists a kempe chain of vertex_pair
  ///           but may not split the boundary into 2 parts
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair colorings)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  const size_t c = coloring.get(vertex_pair.first);
  const size_t d = coloring.get(vertex_pair.second);
  if (c == d) {
    /// 0. vertex_pair have the same color
    DEBUG << "0. c==d\n";
    for (size_t color = 0; color < COLORS; ++color) {
      if (color == c) continue;
      this->run(ring, coloring, vertex_pair, {c, color}, colorings);
    }/// for
  } else {
    /// 1. vertex_pair have distinct colors
    DEBUG << "1. c!=d\n";
    this->run(ring, coloring, vertex_pair, {c, d}, colorings);
  }/// else c != d
  DEBUG_OBJ(*colorings)
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair colorings)
  return !colorings->empty();
}/// BirkhoffDiamondKempeChainInterchanger::run 

bool BirkhoffDiamondKempeChainInterchanger::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, ColorResult* colorings) {
  /// assuming: there exists a kempe chain of vertex_pair
  ///           with color_pair
  ///           but this kempe chain may not split the boundary into 2 parts
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
    res = true;
    for (const auto& separated_vertex_pair : chain.separatedVertexPairs(ring.boundarySize())) {
      DEBUG_PAIR(separated_vertex_pair)
      const size_t c = coloring.get(separated_vertex_pair.first);
      const size_t d = coloring.get(separated_vertex_pair.second);
      if (c == d) {
        /// 1.0 if separated_vertex_pair have the same color
        DEBUG << "1.0 c==d\n";
        std::vector<size_t> unused_colors;
        diff<size_t>(id<size_t>(COLORS), {c, color_pair.first, color_pair.second}, &unused_colors);
        for (const auto& unused_color : unused_colors) {
          this->interchange(ring, coloring, separated_vertex_pair, {c, unused_color}, colorings);
        }/// for unused_color
      } else {
        /// 1.1 else separated_vertex_pair have distinct colors
        DEBUG << "1.1 c!=d\n";
        this->interchange(ring, coloring, separated_vertex_pair, {c, d}, colorings);
      }/// else c != d
    }/// for separated_vertex_pair
  }/// else chain.size() >= 2
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::run ring coloring vertex_pair color_pair colorings)
  return res;
}/// BirkhoffDiamondKempeChainInterchanger::run

void BirkhoffDiamondKempeChainInterchanger::interchange(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, ColorResult* colorings) {
  /// assuming: vertex_pair is separated by another kempe chain
  /// interchange the kempe chain induced by vertex_pair with color_pair
  DEBUG_START(BirkhoffDiamondKempeChainInterchanger::interchange)
  DEBUG_OBJ(coloring)
  DEBUG_PAIR(vertex_pair)
  DEBUG_PAIR(color_pair)
  KempeChain chain;
  ColorInducer inducer;
  inducer.run(ring, coloring, vertex_pair, color_pair, &chain);
  DEBUG_VAR(chain.size()) /// chain size must be 2
  NaiveColorRepresentation coloring_0(coloring.getVector());
  coloring_0.inverse(chain.getConst(0), color_pair);
  DEBUG_OBJ(coloring_0)
  colorings->append(coloring_0);
  NaiveColorRepresentation coloring_1(coloring.getVector());
  coloring_1.inverse(chain.getConst(1), color_pair);
  DEBUG_OBJ(coloring_1)
  colorings->append(coloring_1);
  DEBUG_END(BirkhoffDiamondKempeChainInterchanger::interchange)
}/// BirkhoffDiamondKempeChainInterchanger::interchange

}/// namespace PlanarGraphColoring
