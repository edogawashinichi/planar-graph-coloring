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
  inline std::vector<int> getVS(const int index) const {
    return vertex_symmetry_.get(index);
  }
  inline std::vector<int> getBBN(const int vertex) const {
    return boundary_backward_neighbors_.count(vertex) ? boundary_backward_neighbors_.at(vertex) : std::vector<int>();
  }
  inline std::vector<int> getIBN(const int vertex) const {
    return interior_backward_neighbors_.count(vertex) ? interior_backward_neighbors_.at(vertex) : std::vector<int>();
  }
  virtual void show() const override;

protected:
  VertexSymmetry vertex_symmetry_;
  std::unordered_map<int, std::vector<int>> boundary_backward_neighbors_;
  std::unordered_map<int, std::vector<int>> interior_backward_neighbors_;
};/// class BirkhoffDiamond

}/// namespace PlanarGraphColoring
