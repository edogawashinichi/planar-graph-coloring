/// dimension_two_vector.h

#pragma once

#include "../notation.h"
#include "../math.h"
#include <vector>

namespace PlanarGraphColoring {

template<typename T>
class DimensionTwoVector {
public:
  DimensionTwoVector() {
    vvt_.clear();
  }/// DimensionTwoVector default
  DimensionTwoVector(const DimensionTwoVector& rhs) {
    vvt_ = rhs.vvt_;
  }/// DimensionTwoVector deepcopy
  DimensionTwoVector(DimensionTwoVector&& rhs) {
    vvt_.swap(rhs.vvt_);
  }/// DimensionTwoVector movecopy
  DimensionTwoVector& operator=(const DimensionTwoVector& rhs) {
    vvt_ = rhs.vvt_;
    return *this;
  }/// DimensionTwoVector assignment
  inline void set(const std::vector<std::vector<T>>& vvt) {
    vvt_ = vvt;
  }/// set
  inline void append(const std::vector<T>& vt) {
    vvt_.emplace_back(vt);
  }/// append
  inline void append(const T& t) {
    vvt_.emplace_back(std::vector<T>());
    vvt_.back().emplace_back(t);
  }/// append
  inline void extend(const T& t)  {
    /// assuming: vvt_ not empty
    vvt_.back().emplace_back(t);
  }/// extend
  inline size_t size() const {
    return vvt_.size();
  }/// size
  inline size_t size(const size_t index) const {
    /// assuming: index valid
    return vvt_[index].size();
  }/// size
  inline const std::vector<std::vector<T>>& getConst() const {
    return vvt_;
  }/// getConst
  inline const std::vector<T>& getConst(const size_t index) const {
    /// assuming: index valid
    return vvt_[index];
  }/// getConst
  inline const T& getConst(const size_t i,  const size_t j) const {
    /// assuming: i,j valid
    return vvt_[i][j];
  }/// getConst
  inline virtual void show() const {
    TEST_INFO
    PGC__SHOW_VVI(vvt_)
  }/// show
  inline virtual void sort() {
    dict_sort<T>(vvt_);
  }/// sort
protected:
  std::vector<std::vector<T>>& get() {
    return vvt_;
  }/// get
protected:
  std::vector<std::vector<T>> vvt_;
};/// class DimensionTwoVector

}/// namespace PlanarGraphColoring
