/// component.h

#pragma once

#include "../basic/notation.h"
#include "../basic/structure/dimension_one_vector.h"
#include "../basic/structure/dimension_two_vector.h"

namespace PlanarGraphColoring {

class Component : public DimensionOneVector<size_t> {
public:
  DERIVE_CLASS_5_FUNCTIONS(Component, DimensionOneVector<size_t>)
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    PGC__SHOW_ENDL(cout, "component:")
    PGC__SHOW_VEC(cout, DimensionOneVector<size_t>::getConst())
  }/// show
};/// class Component

class Components : public DimensionTwoVector<size_t> {
public:
  DERIVE_CLASS_5_FUNCTIONS(Components, DimensionTwoVector<size_t>)
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    PGC__SHOW_ENDL(cout, "components:")
    PGC__SHOW_VVI_WITH_INDEX(cout, DimensionTwoVector<size_t>::getConst())
  }/// show
};/// class Components

}/// namespace PlanarGraphColoring
