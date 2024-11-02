/// symmetry.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

class Transformation {
public:
  Transformation() = default;
  Transformation(const std::vector<size_t>& trans);
  std::vector<size_t> inverse() const;
  ///TODO
  //multiply
protected:
  std::vector<size_t> trans_;
};/// class Transformation

class VertexSymmetry {
protected:
  std::vector<std::vector<size_t>> mappers_;

public:
  VertexSymmetry() = default;
  VertexSymmetry(const std::vector<std::vector<size_t>>& mappers);
  void set(const std::vector<std::vector<size_t>>& mappers);
  std::vector<size_t> get(const size_t index) const;
  inline size_t size() const {
    return mappers_.size();
  }
  void show() const;
};/// class VertexSymmetry

}/// PlanarGraphColoring
