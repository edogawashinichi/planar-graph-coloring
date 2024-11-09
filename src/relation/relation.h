/// relation.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

class Relation {
public:
  Relation()=default;
  Relation(const size_t from, const size_t to, const size_t type, const std::vector<size_t>& mapper);
  void show() const;
protected:
  size_t from_;
  size_t to_;
  size_t type_;/// 0-vertex_symmetry 1-color_symmetry 2-Kempe_chain_interchange
  std::vector<size_t> mapper_;
};/// class Relation

}/// namespace PlanarGraphColoring
