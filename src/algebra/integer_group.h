/// integer_group.h

/// IntegerMod(n): i % n
/// parameter: positive integer n
/// Zn = {i % n: for any integer i}
/// operation + : i % n + j % n = (i + j) % n

#pragma once

#include "group.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

template <size_t N>
class IntegerMod {
public:
  inline IntegerMod<N>() : i_(0) {
  }/// constructor default
  inline IntegerMod<N>(const IntegerMod<N>& rhs) : i_(rhs.i_) {
  } /// constructor deepcopy
  inline IntegerMod<N>(IntegerMod<N>&& rhs) {
    if (this != &rhs) {
      std::swap(i_, rhs.i_);
    }
  }/// constructor movecopy
  inline IntegerMod<N>& operator=(const IntegerMod<N>& rhs) {
    if (this != &rhs) {
      i_ = rhs.i_;
    }
    return *this;
  }/// operator= assignment deepcopy
  inline IntegerMod<N>& operator=(IntegerMod<N>&& rhs) {
    if (this != &rhs) {
      std::swap(i_, rhs.i_);
    }
    return *this;
  }/// operator= assignment movecopy
  inline IntegerMod<N>(const size_t i) : i_(IntegerMod<N>::MOD(i)) {
  }/// constructor
  inline static size_t MOD(const size_t value) {
    return value % N;
  }/// static MOD
  inline size_t get() const {
    return IntegerMod<N>::MOD(i_);
  }/// get
  inline void show() const {
    TEST_INFO
    std::cout << this->get() << "\n";
  }/// show
  inline bool id() const {
    return 0 == this->get();
  }/// id
  inline size_t order() const {
    size_t res = 1;
    IntegerMod<N> product(i_);
    while (!product.id()) {
      product = product * (*this);
      ++res;
    }/// while
    return res;
  }/// order
  inline friend IntegerMod<N> operator*(const IntegerMod<N>& lhs, const IntegerMod<N>& rhs) {
    return IntegerMod<N>(lhs.i_ + rhs.i_);
  }/// friend operator*
  inline friend bool operator==(const IntegerMod<N>& lhs, const IntegerMod<N>& rhs) {
    return lhs.get() == rhs.get();
  }/// friend operator==
  inline friend bool operator!=(const IntegerMod<N>& lhs, const IntegerMod<N>& rhs) {
    return lhs.get() != rhs.get();
  }/// friend operator!=
  inline friend std::ostream& operator<<(std::ostream& cout, const IntegerMod<N>& obj) {
    obj.show();
    return cout;
  }/// friend operator<<
protected:
  size_t i_;
};/// class IntegerMod<N>

template<size_t N>
class IntegerGroup : public Group<IntegerMod<N>> {
public:
  inline IntegerGroup<N>() : Group<IntegerMod<N>>(N) {
    for (size_t i = 0; i < N; ++i) {
      Group<IntegerMod<N>>::element(i) = std::move(IntegerMod<N>(i));
    }
  }/// constructor default 
};/// class IntegerGroup

}/// namespace PlanarGraphColoring
