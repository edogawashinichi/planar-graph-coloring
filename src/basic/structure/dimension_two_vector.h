/// dimension_two_vector.h

#pragma once

#include "../notation.h"
#include "../math.h"
#include <vector>
#include <algorithm>

namespace PlanarGraphColoring {

template<typename T>
class DimensionTwoVector {
public:
  DimensionTwoVector() {
    vvt_.clear();
  }/// DimensionTwoVector default
  DimensionTwoVector(const DimensionTwoVector& rhs) {
    if (this != &rhs) {
      vvt_ = rhs.vvt_;
    }
  }/// DimensionTwoVector deepcopy
  DimensionTwoVector(DimensionTwoVector&& rhs) {
    if (this != &rhs) {
      vvt_.swap(rhs.vvt_);
    }
  }/// DimensionTwoVector movecopy
  DimensionTwoVector& operator=(const DimensionTwoVector& rhs) {
    if (this != &rhs) {
      vvt_ = rhs.vvt_;
    }
    return *this;
  }/// DimensionTwoVector assignment deepcopy
  DimensionTwoVector& operator=(DimensionTwoVector&& rhs) {
    if (this != &rhs) {
      vvt_.swap(rhs.vvt_);
    }
    return *this;
  }
  inline void get(const size_t index, size_t* r, size_t* c) {
    /// assuming: index valid
    const size_t col = vvt_.front().size();
    *r = index / col;
    *c = index % col;
  }/// get
  inline void set(const size_t row, const size_t col) {
    for (size_t r = 0; r < row; ++r) {
      std::vector<T> vt(col);/// col Ts of type T default value
      for (size_t c = 0; c < col; ++c) {
        vt[c] = T(r * col + c);
      }/// for col
      vvt_.emplace_back(vt);
    }/// for row
  }/// set
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
  inline virtual size_t size() const {
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
  inline T& get(const size_t i, const size_t j) {
    /// assuming: i,j valid
    return vvt_[i][j];
  }/// get
  inline const T& getConst(const size_t i,  const size_t j) const {
    /// assuming: i,j valid
    return vvt_[i][j];
  }/// getConst
  /*  
  inline virtual void show() const {
    TEST_INFO
    PGC__SHOW_VVI(vvt_)
  }/// show
  */
  inline virtual void sort() {
    dict_sort<T>(vvt_);
  }/// sort
  inline std::vector<std::vector<T>>& get() {
    return vvt_;
  }/// get
  inline bool contain(const T& t) const {
    bool res = false;
    for (const auto& vt : vvt_) {
      if (std::find(vt.begin(), vt.end(), t) == vt.end()) continue;
      res = true;
      break;
    }
    return res;
  }
protected:
  std::vector<std::vector<T>> vvt_;
};/// class DimensionTwoVector

}/// namespace PlanarGraphColoring
