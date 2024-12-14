/// weak_componnet.h

#pragma once

#include "component.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class WeakComponent : public Component {
public:
  CLASS_5_FUNCTIONS(WeakComponent, Component)
  inline virtual void show() const override {
    TEST_INFO
    std::cout << "WeakComponent:\n";
    Component::show();
  }/// show
};/// class WeakComponent

class WeakComponents : public Components {
public:
  CLASS_5_FUNCTIONS(WeakComponents, Components)
  inline virtual void show() const override {
    TEST_INFO
    std::cout << "WeakComponents:\n";
    Components::show();
  }/// show
};/// class WeakComponents

}/// namespace PlanarGraphColoring
