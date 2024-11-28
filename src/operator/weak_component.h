/// weak_componnet.h

#pragma once

#include "component.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class WeakComponent : public Component {
public:
  inline virtual void show() const override {
    Component::show();
  }
  inline void append(const size_t vertex) {
    const std::vector<size_t> last = {vertex};
    c_.emplace_back(last);
  }
  inline void extend(const size_t vertex) {
    /// assumming: c_ not empty
    c_.back().emplace_back(vertex);
  }
};/// class WeakComponent

}/// namespace PlanarGraphColoring
