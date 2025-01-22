/// group.h

/// definition of group:
/// 0. a set G
/// 1. (closure) multiply operation X: G X G --> G
/// 2. (association): a X b X c = (a X b) X c = a X (b X c)
/// 3. (unit) unique unit element 1: 1 X e = e X 1 = e
/// 4. (inverse) unique inverse element i: e X i = i X e = 1 
///
/// assuming: finite group
/// template interface

#pragma once

#include "../basic/structure/dimension_one_vector.h"

namespace PlanarGraphColoring {

template<typename T>
class Group : public DimensionOneVector<T> {
public:
  inline Group<T>() = default;
  inline Group<T>(const size_t n) : DimensionOneVector<T>(n) {}
  /// WARNING: extract orbit of type T
  inline virtual std::vector<T> orbit(const T& element) const {
    std::vector<T> res;
    res.emplace_back(this->unit());
    T product(element);
    while (!product.id()) {
      res.emplace_back(product);
      product = product * element;
    }/// while
    return res;
  }/// orbit
  inline size_t size() const {
    return DimensionOneVector<T>::size();
  }/// size
  inline virtual void show() const {
    TEST_INFO
    for (size_t i = 0; i < this->size(); ++i) {
      std::cout << i << "th: ";
      this->constElement(i).show();
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
    const size_t i = this->index(product);
    return this->constElement(i);
  }/// multiply
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
};/// class Group

}/// namespace PlanarGraphColoring
