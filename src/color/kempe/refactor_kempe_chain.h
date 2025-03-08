/// refactor_kempe_chain.h

/// without context of a ring

#pragma once

#include "../../basic/structure/dimension_two_vector.h"
#include "../coloring_result.h"
#include <utility>

namespace PlanarGraphColoring {

class KempeChainConnector {
public:
  II vertex_pair_;
  II color_pair_;
public:
  CLASS_5_FUNCTIONS_VARIABLE(KempeChainConnector, vertex_pair_, color_pair_)
  KempeChainConnector(const II& vertex_pair, const II& color_pair) : vertex_pair_(vertex_pair), color_pair_(color_pair) {}
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(vertex_pair_)
    INFO_PAIR(color_pair_)
  }/// show
};/// class KempeChainConnector

/*
class KempeChainInfo {
public:
  II color_pair_;
  KempeChainConnector dual_;
  NaiveColorRepresentation interchange_;
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(color_pair_)
    INFO_OBJ(dual_)
    INFO_OBJ(interchange_)
  }/// show
};/// class KempeChainInfo

class KempeChainResult {
public:
  II vertex_pair_;
  KempeChainInfo separating_;
  KempeChainInfo separated_;
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(vertex_pair_)
    INFO_OBJ(separating_)
    INFO_OBJ(separated_)
  }/// show
};/// class KempeChainResult

class KempeChain : public DimensionTwoVector<size_t> {
public:
  DERIVE_CLASS_5_FUNCTIONS(KempeChain, DimensionTwoVector<size_t>)
  virtual void show(std::ostream& cout) const override;
  void sort(const size_t ring_size);
  const VII getSeparatedVertexPairs(const size_t ring_size) const;
  size_t getMaxValue() const;
  inline std::vector<std::vector<size_t>>& get() {
    return DimensionTwoVector<size_t>::get();
  }
  inline const std::vector<size_t>& getConst(const size_t index) const {
    return DimensionTwoVector<size_t>::getConst(index);
  } 
  inline const std::vector<std::vector<size_t>>& getConst() const {
    return DimensionTwoVector<size_t>::getConst();
  }
};/// class KempeChain
*/

}/// namespace PlanarGraphColoring
