/// group.h

/// definition of group:
/// 0. a set G
/// 1. (closure) multiply operation X: G X G --> G
/// 2. (association): a X b X c = (a X b) X c = a X (b X c)
/// 3. (unit) unique unit element 1: 1 X e = e X 1 = e
/// 4. (inverse) unique inverse element i: e X i = i X e = 1 
///
/// assuming: finite group
/// template typename T: Permutation / IntegerMod<N>

#pragma once

#include "../basic/structure/dimension_one_vector.h"

namespace PlanarGraphColoring {

template<typename T>
class Group : public DimensionOneVector<T> {
public:
  inline Group<T>() : DimensionOneVector<T>() {
  }/// constructor default
  inline Group<T>(const size_t n) : DimensionOneVector<T>(n) {
  }/// constructor
  inline virtual VI orbit(const T& element) const {
    VI res;
    T product(this->unit());
    do {
      res.emplace_back(this->index(product));
      product = product * element;
    } while (!product.id());
    return res;
  }/// orbit
  inline size_t size() const {
    return DimensionOneVector<T>::size();
  }/// size
  inline virtual void show(std::ostream& cout) const {
    TEST_INFO
    for (size_t i = 0; i < this->size(); ++i) {
      cout << i << "th: ";
      this->constElement(i).show(cout);
    }/// for
  }/// show
  inline virtual const T& unit() const {
    for (const T& element : this->constElements()) {
      if (element.id()) return element;
    }/// for
    return this->constElement(0);
  }/// unit
  inline virtual const T& inverse(const T& element) const {
    for (const T& t : this->constElements()) {
      if (T(t * element).id()) return t;
    }/// for
    return this->constElement(0);
  }/// inverse
  inline virtual const T& multiply(const T& e, const T& f) const {
    T product(e * f);
    return this->constElement(this->index(product));
  }/// multiply
  inline virtual const T& product(const std::vector<T>& elements) const {
    T p(this->unit());
    for (const T& element : elements) {
      p = p * element;
    }
    return this->constElement(this->index(p));
  }/// product
  inline virtual T product(const VI& elements) const {
    T res(this->unit());
    for (const size_t index : elements) {
      res = this->constElement(index) * res;
    }
    return res;
  }/// product
  inline const std::vector<T>& constElements() const {
    return DimensionOneVector<T>::getConst();
  }/// constElements
  inline std::vector<T>& elements() {
    return DimensionOneVector<T>::get();
  }/// elements
  inline const T& constElement(const size_t index) const {
    /// assuming: index valid
    return DimensionOneVector<T>::getConst(index);
  }/// constElement 
  inline T& element(const size_t index) {
    /// assuming: index valid
    return DimensionOneVector<T>::get(index);
  }/// element
  inline int index(const T& element) const {
    return DimensionOneVector<T>::find(element);
  }/// index
  inline VI index(const std::vector<T>& elements) const {
    /// assuming: all elements valid
    VI res;
    for (const T& element : elements) {
      res.emplace_back(static_cast<size_t>(this->index(element)));
    }
    return res;
  }/// index
};/// class Group

}/// namespace PlanarGraphColoring
