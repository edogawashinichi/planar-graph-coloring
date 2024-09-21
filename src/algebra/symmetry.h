/// symmetry.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

class VertexSymmetry {
protected:
  std::vector<std::vector<int>> mappers_;

public:
  VertexSymmetry() = default;
  VertexSymmetry(const std::vector<std::vector<int>>& mappers);
  void set(const std::vector<std::vector<int>>& mappers);
  std::vector<int> get(const size_t index) const;
  inline size_t size() const {
    return mappers_.size();
  }
  void show() const;
};/// class VertexSymmetry

}/// PlanarGraphColoring
