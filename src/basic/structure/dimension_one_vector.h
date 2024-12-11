/// dimension_one_vector.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

template<typename T>
class DimensionOneVector {
public:
  DimensionOneVector() {
    vt_.clear();
  }/// DimensionOneVector default
  DimensionOneVector(const DimensionOneVector& rhs) {
    vt_ = rhs;
  }/// DimensionOneVector deepcopy
  DimensionOneVector(DimensionOneVector&& rhs) {
    vt_.swap(rhs);
  }/// DimensionOneVector movecopy
  DimensionOneVector& operator=(const DimensionOneVector& rhs) {
    vt_ = rhs;
    return *this;
  }/// DimensionOneVector assignment
  inline const std::vector<T>& getConst() const {
    return vt_;
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
