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
  inline KempeChainConnector(const II& vertex_pair, const II& color_pair) : vertex_pair_(vertex_pair), color_pair_(color_pair) {}/// constructor
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(vertex_pair_)
    INFO_PAIR(color_pair_)
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const KempeChainConnector& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class KempeChainConnector

class KempeChainInfo {
public:
  II color_pair_;
  KempeChainConnector dual_;
  Coloring interchange_;
public:
  CLASS_5_FUNCTIONS_VARIABLE(KempeChainInfo, color_pair_, dual_, interchange_)
  inline KempeChainInfo(const II& color_pair, const KempeChainConnector& dual, const Coloring& interchange) {
    color_pair_ = color_pair;
    dual_ = dual;
    interchange_ = interchange;
  }/// constructor
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(color_pair_)
    INFO_OBJ(dual_)
    INFO_OBJ(interchange_)
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const KempeChainInfo& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class KempeChainInfo

class KempeChainInfoResult {
public:
  II vertex_pair_;
  KempeChainInfo separating_;
  KempeChainInfo separated_;
public:
  CLASS_5_FUNCTIONS_VARIABLE(KempeChainInfoResult, vertex_pair_, separating_, separated_)
  inline KempeChainInfoResult(const II& vertex_pair, const KempeChainInfo& separating, const KempeChainInfo& separated){
    vertex_pair_ = vertex_pair;
    separating_ = separating;
    separated_ = separated;
  }/// constructor
  inline void show(std::ostream& cout) const {
    TEST_INFO
    INFO_PAIR(vertex_pair_)
    INFO_OBJ(separating_)
    INFO_OBJ(separated_)
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const KempeChainInfoResult& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class KempeChainInfoResult

class KempeChain : public DimensionTwoVector<size_t> {
public:
  DERIVE_CLASS_5_FUNCTIONS(KempeChain, DimensionTwoVector<size_t>)
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "KempeChain:\n";
    PGC__SHOW_VVI_WITH_INDEX(cout, this->getConst())
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const KempeChain& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
  inline void sort(const size_t ring_size) {
    cycle_sort(this->get(), ring_size);
  }/// sort
  inline const VII getSeparatedVertexPairs(const size_t ring_size) const {
    /* assuming: this size = 2 */
    /* assuming: this cycle sorted */
    VII res;
    for (size_t i = (this->getConst(0).back() + 1) % ring_size; i != this->getConst(1).front(); i = (i + 1) % ring_size) {
      for (size_t j = (this->getConst(1).back() + 1) % ring_size; j != this->getConst(0).front(); j = (j + 1) % ring_size) {
        res.emplace_back(std::pair<size_t, size_t>({i, j}));
      }/* for j */
    }/* for i */
    return res;
  }/// getSeparatedVertexPairs
  inline size_t getMaxValue() const {
    size_t res = 0;
    for (const auto& vec : DimensionTwoVector<size_t>::getConst()) {
      res = std::max(res, *max_element(vec.begin(), vec.end()));
    }/* for */
    return res;
  }/// getMaxValue
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

}/// namespace PlanarGraphColoring
