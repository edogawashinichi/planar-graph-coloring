/// birkhoff_diamond_color_judger.cxx

#include "birkhoff_diamond_color_judger.h"
#include "naive_color_representation.h"
#include "color_transformer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  std::vector<size_t> mapper;
  return isIsomorphismByVertexSymmetry(lhs, rhs, &mapper);
}/// BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry(const std::vector<size_t>& lhs, const std::vector<size_t>& rhs, std::vector<size_t>* mapper) {
  const NaiveColorRepresentation ncr_lhs(lhs);
  const NaiveColorRepresentation ncr_rhs(rhs);
  return isIsomorphismByVertexSymmetry(ncr_lhs, ncr_rhs, mapper);
}/// BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs, std::vector<size_t>* mapper) {
  /*PGC__SHOW_ENDL("start isIsomorphismByVertexSymmetry")
  PGC__SHOW_ENDL("lhs:")
  lhs.show();
  PGC__SHOW_ENDL("rhs:")
  rhs.show();*/
  BirkhoffDiamond bd;
  ColorTransformer ct;
  bool res = false;
  mapper->clear();
  for (size_t i = 0; i < bd.getVS().size(); ++i) {
    NaiveColorRepresentation ncr;
    ct.transformByVertexSymmetry(bd.getVS().get(i), lhs, &ncr);
    if (rhs.equal(ncr)) {
      *mapper = bd.getVS().get(i);
      res = true;
      break;
    }
  }
  /*PGC__SHOW_ENDL("mapper:")
  PGC__SHOW_VEC_WITH_INDEX((*mapper))
  PGC__SHOW_VAR(res)
  PGC__SHOW_ENDL("end isIsomorphismByVertexSymmetry")*/
  return res;
}/// BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  std::vector<size_t> mapper;
  return isIsomorphismByColorSymmetry(lhs, rhs, &mapper);
}/// BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry(const std::vector<size_t>& lhs, const std::vector<size_t>& rhs, std::vector<size_t>* mapper) {
  const NaiveColorRepresentation ncr_lhs(lhs);
  const NaiveColorRepresentation ncr_rhs(rhs);
  return isIsomorphismByColorSymmetry(ncr_lhs, ncr_rhs, mapper);
}/// BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry(const ColorRepresentation& lhs, const ColorRepresentation& rhs, std::vector<size_t>* mapper) {
  /// assuming lhs.size == rhs.size
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("start isIsomorphismByColorSymmetry")
    PGC__SHOW_ENDL("lhs:")
    lhs.show();
    PGC__SHOW_ENDL("rhs:")
    rhs.show();
  }
  std::unordered_map<size_t, size_t> f, g;
  bool res = true;
  mapper->clear();
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (f.count(lhs.get(i))) {
      if (f[lhs.get(i)] != rhs.get(i)) {
        if (PGC__DEBUG_MODE) {
          PGC__SHOW_ENDL("false")
          std::cout << lhs.get(i) << "->" << f[lhs.get(i)] << "\n";
          std::cout << "duplicate " << lhs.get(i) << "->" << rhs.get(i) << "\n";
        }
        res = false;
        break;
      }
    }
    if (g.count(rhs.get(i))) {
      if (g[rhs.get(i)] != lhs.get(i)) {
        if (PGC__DEBUG_MODE) {
          PGC__SHOW_ENDL("false")
          std::cout << g[rhs.get(i)] << "<-" << rhs.get(i) << "\n";
          std::cout << "duplicate " << lhs.get(i) << "<-" << rhs.get(i) << "\n";
        }
        res = false;
        break;
      }
    }
    if (!f.count(lhs.get(i)) && !g.count(rhs.get(i))) {
      f[lhs.get(i)] = rhs.get(i);
      g[rhs.get(i)] = lhs.get(i);
    }
  }
  (*mapper) = id<size_t>(lhs.size());
  for (const auto& kv : f) {
    (*mapper)[kv.first] = kv.second;
  }
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("mapper:")
    PGC__SHOW_VEC_WITH_INDEX((*mapper))
    PGC__SHOW_VAR(res)
    PGC__SHOW_ENDL("end isIsomorphismByColorSymmetry")
  }
  return res;
}/// BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  return true;
}/// BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation

}/// namespace PlanarGraphColoring
