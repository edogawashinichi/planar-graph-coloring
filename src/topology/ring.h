/// ring.h

/// configuration of a ring: including both the boundary and the interior (which may be empty)

#pragma once

#include "planar_graph.h"

namespace PlanarGraphColoring {

class Ring : public PlanarGraph {
protected:
  size_t k_; /// size of the boundary 
public:
  Ring() = default;
  Ring(const size_t k, const size_t n, const std::vector<std::vector<size_t>>& edges);
  inline size_t boundarySize() const {
    return k_;
  }
  inline size_t interiorSize() const {
    return n_ - k_;
  }
  virtual void show() const override;
};/// class Ring

}/// namespace PlanarGraphColoring
