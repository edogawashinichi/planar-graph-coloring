/// birkhoff_diamond_color_judger.cxx

#include "birkhoff_diamond_color_judger.h"
#include "naive_color_representation.h"
#include "color_transformer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

bool BirkhoffDiamondColorJudger::isValid(const ColorRepresentation& coloring) {
  BirkhoffDiamond diamond;
  bool res = coloring.valid();
  VERBOSE << "coloring.valid():\n";
  VERBOSE_VAR(res)
  res = res && this->isBoundaryColoringValid(diamond, coloring);
  VERBOSE << "isBoundaryColoringValid:\n";
  VERBOSE_VAR(res)
  /// TODO: isInteriorColoringValid
  return res;
}/// BirkhoffDiamondColorJudger::isValid

bool BirkhoffDiamondColorJudger::isBoundaryColoringValid(const Ring& ring, const ColorRepresentation& coloring) {
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(ring);
  const int k = birkhoff_diamond.boundarySize();
  bool res = true;
  for (int i = 0; i < k; ++i) {
    if (coloring.get(i % k) == coloring.get((i + 1) % k)) {
      res = false;
      break;
    }
  }
  return res;
}/// BirkhoffDiamondColorJudger::isBoundaryColoringValid

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
  VERBOSE_START(BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry)
  BirkhoffDiamond bd;
  ColorTransformer ct;
  bool res = false;
  mapper->assign(lhs.size(), 0);
  for (size_t i = 0; i < bd.getVS().size(); ++i) {
    NaiveColorRepresentation ncr;
    ct.transformByVertexSymmetry(bd.getVS().get(i), lhs, &ncr);
    if (rhs.equal(ncr)) {
      *mapper = bd.getVS().get(i);
      res = true;
      break;
    }
  }
  VERBOSE_END(BirkhoffDiamondColorJudger::isIsomorphismByVertexSymmetry)
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
  VERBOSE_START(BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry)
  VERBOSE_OBJ(lhs)
  VERBOSE_OBJ(rhs)
  bool res = true;
  std::unordered_map<size_t, size_t> f, g;
  res = res && function<size_t>(lhs.getVector(), rhs.getVector(), &f);
  res = res && function<size_t>(rhs.getVector(), lhs.getVector(), &g);
  /// TODO: refactor function/injection/surjection/bijection representation
  if (res) {
    mapper->resize(COLORS, UNDEF_COLOR);
    VI f_keys, g_keys;
    for (const auto& kv : f) {
      (*mapper)[kv.first] = kv.second;
      f_keys.emplace_back(kv.first);
      g_keys.emplace_back(kv.second);
    }/// for
    VERBOSE_VEC(f_keys)
    VERBOSE_VEC(g_keys)
    VI f_keys_res, g_keys_res;
    diff<size_t>(id<size_t>(COLORS), f_keys, &f_keys_res);
    diff<size_t>(id<size_t>(COLORS), g_keys, &g_keys_res);
    VERBOSE_VEC(f_keys_res)
    VERBOSE_VEC(g_keys_res)
    for (size_t i = 0; i < f_keys_res.size(); ++i) {
      const size_t x = f_keys_res[i];
      const size_t y = g_keys_res[i];
      (*mapper)[x] = y;
    }
  }/// if res
  VERBOSE_END(BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry)
  return res;
}/// BirkhoffDiamondColorJudger::isIsomorphismByColorSymmetry

bool BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation(const ColorRepresentation& lhs, const ColorRepresentation& rhs) {
  return true;
}/// BirkhoffDiamondColorJudger::isIsomorphismByKempeChainTransformation

}/// namespace PlanarGraphColoring
