/// dimension_one_vector.h

#pragma once

#include "../notation.h"

namespace PlanarGraphColoring {

template<typename T>
class DimensionOneVector {
public:
  CLASS_4_FUNCTIONS(DimensionOneVector, vt_)
  DimensionOneVector() {
    vt_.clear();
  }/// DimensionOneVector constructordefault
  inline const std::vector<T>& getConst() const {
    return vt_;
  }/// getConst
  inline const T& getConst(const size_t index) const {
    /// assuming: index valid
    return vt_[index];
  }/// getConst
  inline std::vector<T>& get() {
    return vt_;
  }/// get
  inline T& get(const size_t index) {
    /// assuming: index valid
    return vt_[index];
  }/// get
  inline void append(const T& t) {
    vt_.emplace_back(t);
  }/// append
  inline size_t size() const {
    return vt_.size();
  }/// size
  inline virtual void show() const {
    TEST_INFO
    PGC__SHOW_VEC(vt_)
  }/// show
protected:
  std::vector<T> vt_;
};/// class DimensionOneVector

}/// namespace PlanarGraphColoring
