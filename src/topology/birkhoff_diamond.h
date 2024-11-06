/// birkhoff_diamond.h

#pragma once

#include "ring.h"
#include "../algebra/symmetry.h"

namespace PlanarGraphColoring {

class BirkhoffDiamond: public Ring {
public:
  BirkhoffDiamond();
  inline bool isBoundary(const size_t vertex) const {
    return vertex < k_;
  }
  inline const VertexSymmetry& getVS() const {
    return vertex_symmetry_;
  }
  inline std::vector<size_t> getVS(const size_t index) const {
    return vertex_symmetry_.get(index);
  }
  inline std::vector<size_t> getBBN(const size_t vertex) const {
    return boundary_backward_neighbors_.count(vertex) ? boundary_backward_neighbors_.at(vertex) : std::vector<size_t>();
  }
  inline std::vector<size_t> getIBN(const size_t vertex) const {
    return interior_backward_neighbors_.count(vertex) ? interior_backward_neighbors_.at(vertex) : std::vector<size_t>();
  }
  virtual void show() const override;

protected:
  VertexSymmetry vertex_symmetry_;
  std::unordered_map<size_t, std::vector<size_t>> boundary_backward_neighbors_;
  std::unordered_map<size_t, std::vector<size_t>> interior_backward_neighbors_;
};/// class BirkhoffDiamond

}/// namespace PlanarGraphColoring
