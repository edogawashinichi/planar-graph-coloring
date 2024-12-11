/// component.h

#pragma once

#include "../basic/notation.h"
#include "../basic/structure/dimension_one_vector.h"
#include "../basic/structure/dimension_two_vector.h"

namespace PlanarGraphColoring {

class Component : public DimensionOneVector<size_t> {
public:
  Component() : DimensionOneVector<size_t>() {}
  Component(const Component& rhs) {
    DimensionOneVector<size_t>::get() = rhs.getConst();
  }/// Component deepcopy
  Component(Component&& rhs) {
    /// WARNING: swap is based on std::move to temp
    /// no error will occur if this==&rhs
    DimensionOneVector<size_t>::get().swap(rhs.get());
  }/// Component movecopy
  Component& operator=(const Component& rhs) {
    DimensionOneVector<size_t>::get() = rhs.getConst();
    return *this;
  }/// Component assignment
  inline virtual void show() const override {
    TEST_INFO
    PGC__SHOW_ENDL("component:")
    PGC__SHOW_VEC(DimensionOneVector<size_t>::getConst())
  }/// show
};/// class Component

class Components : public DimensionTwoVector<size_t> {
public:
  inline virtual void show() const override {
    TEST_INFO
    PGC__SHOW_ENDL("components:")
    PGC__SHOW_VVI_WITH_INDEX(DimensionTwoVector<size_t>::getConst())
  }/// show
};/// class Components

}/// namespace PlanarGraphColoring
