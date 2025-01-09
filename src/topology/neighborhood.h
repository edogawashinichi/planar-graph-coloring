/// neighborhood.h

#pragma once

#include "ring.h"

namespace PlanarGraphColoring {

template <size_t K>
class Neighborhood : public Ring {
public:
  inline Neighborhood() {
    k_ = K;
    n_ = K + 1;
    const VVI edges = {
      {0, 1}, {0, 4}, {0, 5},
      {1, 2}, {1, 5},
      {2, 3}, {2, 5},
      {3, 4}, {3, 5},
      {4, 5}
    };
    for (const auto& edge : edges) {
      Graph::addEdge(edge.front(), edge.back());
    }/// for
  }/// Neighborhood

  inline virtual void show() const override {
    TEST_INFO
    INFO << "neighborhood size: " << k_ << "\n";
    Ring::show();
  }/// show
};/// class Neighborhood

}/// namespace PlanarGraphColoring
