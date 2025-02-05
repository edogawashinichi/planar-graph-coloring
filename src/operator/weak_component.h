/// weak_componnet.h

#pragma once

#include "component.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class WeakComponent : public Component {
public:
  DERIVE_CLASS_5_FUNCTIONS(WeakComponent, Component)
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "WeakComponent:\n";
    Component::show(cout);
  }/// show
};/// class WeakComponent

class WeakComponents : public Components {
public:
  DERIVE_CLASS_5_FUNCTIONS(WeakComponents, Components)
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "WeakComponents:\n";
    Components::show(cout);
  }/// show
};/// class WeakComponents

}/// namespace PlanarGraphColoring
