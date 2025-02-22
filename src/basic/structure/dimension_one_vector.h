/// dimension_one_vector.h

/// WARNING: std::vector memory DATA always on HEAP
///                             object on stack or heap

#pragma once

#include "../notation.h"
#include "../math.h"
#include <ostream>
#include <algorithm>

namespace PlanarGraphColoring {

template<typename T>
class DimensionOneVector {
public:
  CLASS_4_FUNCTIONS(DimensionOneVector, vt_)
  inline DimensionOneVector() {
    vt_.clear();
  }/// DimensionOneVector constructor default
  inline DimensionOneVector(const std::vector<T>& vt) {
    vt_ = vt;
  }/// constructor
  inline DimensionOneVector(const size_t n) {
    vt_.resize(n);
  }/// DimensionOneVector constructor
  inline void clear() {
    vt_.clear();
  }/// clear
  inline void resize(const size_t n) {
    vt_.resize(n);
  }/// resize
  inline const std::vector<T>& getConst() const {
    return vt_;
  }/// getConst
  inline std::vector<T> getCopy(const size_t begin, const size_t end) const {
    /// assuming: beign, end valid
    return std::vector<T>(vt_.begin() + begin, vt_.begin() + end);
  }/// getCopy
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
  inline virtual void show(std::ostream& cout) const {
    TEST_INFO
    PGC__SHOW_VEC(cout, vt_)
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const DimensionOneVector<T>& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
  inline int find(const T& t) const {
    return find_index_in_vector<T>(t, vt_);
  }/// find
  inline void sort() {
    /* warning: type T must define operator< */
    std::sort(this->get().begin(), this->get().end());
  }/// sort
protected:
  std::vector<T> vt_;
};/// class DimensionOneVector

}/// namespace PlanarGraphColoring
