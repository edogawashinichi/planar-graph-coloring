/// birkhoff_diamond_color_judger.cxx

#include "birkhoff_diamond_color_judger.h"
#include "naive_color_representation.h"
#include "color_transformer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  PGC__SHOW_ENDL("lhs show:")
  lhs.show();
  PGC__SHOW_ENDL("rhs show:")
  rhs.show();
  BirkhoffDiamond bd;
  ColorTransformer ct;
  for (size_t i = 0; i < bd.getVS().size(); ++i) {
    std::cout << i << "th:\n";
    NaiveColorRepresentation ncr;
    ct.transformByVertexSymmetry(bd.getVS().get(i), lhs, &ncr);
    PGC__SHOW_ENDL("transform by vertex symmetry:")
    ncr.show();
    if (rhs.equal(ncr)) return true;
  }
  return false;
}/// BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  /// assuming lhs.size == rhs.size
  PGC__SHOW_ENDL("lhs show:")
  lhs.show();
  PGC__SHOW_ENDL("rhs show:")
  rhs.show();
  std::unordered_map<int, int> f, g;
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (f.count(lhs.get(i))) {
      if (f[lhs.get(i)] != rhs.get(i)) {
        PGC__SHOW_ENDL("false")
        std::cout << lhs.get(i) << "->" << f[lhs.get(i)] << "\n";
        std::cout << "duplicate " << lhs.get(i) << "->" << rhs.get(i) << "\n";
        return false;
      }
    }
    if (g.count(rhs.get(i))) {
      if (g[rhs.get(i)] != lhs.get(i)) {
        PGC__SHOW_ENDL("false")
        std::cout << g[rhs.get(i)] << "<-" << rhs.get(i) << "\n";
        std::cout << "duplicate " << lhs.get(i) << "<-" << rhs.get(i) << "\n";
        return true;
      }
    }
    if (!f.count(lhs.get(i)) && !g.count(rhs.get(i))) {
      f[lhs.get(i)] = rhs.get(i);
      g[rhs.get(i)] = lhs.get(i);
    }
  }
  PGC__SHOW_ENDL("true")
  PGC__SHOW_MII(f)
  return true;
}/// BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  return true;
}/// BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation

}/// namespace PlanarGraphColoring
