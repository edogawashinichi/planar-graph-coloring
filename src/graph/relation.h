/// relation.h

#pragma once

#include "../color/color_representation.h"

#include <unordered_map>
#include <vector>

namespace PlanarGraphColoring {

class Mapper {
public:
  std::unordered_map<size_t, ColorRepresentation*> index2coloring_;
  std::unordered_map<ColorRepresentation*, size_t> coloring2index_;
  
  void show(const size_t n) const;
};/// class Mapper

class Operation {
public:
  /* type_0 - color symmetry
     type_1 - vertex symmetry
     type_2 - Kempe chain interchange */
  int type_;
  std::vector<size_t> color_mapper_; /// for type_0 type_2
  std::vector<size_t> vertex_mapper_; /// for type_1
public:
  Operation() = default;
  Operation(const int type);
  Operation(const int type, const std::vector<size_t>& mapper);
};/// class Operation

constexpr size_t HASH_MAX_N = 10000;
struct pair_hash {
  std::size_t operator() (const std::pair<size_t, size_t>& p) const {
    return p.first * HASH_MAX_N + p.second;
  }
};/// struct pair_hash
class Relation {
public:
  std::unordered_map<size_t, std::vector<size_t>> successors_;
  std::unordered_map<size_t, std::vector<size_t>> predecessors_;
  std::unordered_map<std::pair<size_t, size_t>, Operation, pair_hash> arcs_;
public:
  void add(const size_t i, const size_t j, const int type, const std::vector<size_t>& mapper, const std::vector<size_t>& imapper);
};/// class Relation

}/// namespace PlanarGraphColoring
