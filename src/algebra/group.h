/// group.h

/// definition of group:
/// 0. a set G
/// 1. (closure) multiply operation X: G X G --> G
/// 2. (association): a X b X c = (a X b) X c = a X (b X c)
/// 3. (unit) unique unit element 1: 1 X e = e X 1 = e
/// 4. (inverse) unique inverse element i: e X i = i X e = 1 

#pragma once

#include "../basic/structure/dimension_one_vector.h"

namespace PlanarGraphColoring {

template<typename T>
class Group : public DimensionOneVector<T> {
public:
  virtual void show() const = 0;
  virtual const T& unit() const = 0;
  virtual const T& inverse(const T& element) const = 0;
  virtual const T& multiply(const T& e, const T& f) const = 0;
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
};/// class Group

}/// namespace PlanarGraphColoring
