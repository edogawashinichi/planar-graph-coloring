/// relation.cxx

#include "relation.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void Mapper::show(const size_t n) const {
  if (!PGC__DEBUG_MODE) return;
  size_t i = 0;
  for (const auto& kv : index2coloring_) {
    if (i++ >= n) break;
    std::cout << kv.first << "th: ";
    (kv.second)->show();
  }
}/// Mapper::show

Operation::Operation(const int type) {
  type_ = type;
}/// Operation::Operation

Operation::Operation(const int type, const std::vector<size_t>& mapper) {
  type_ = type;
  if (0 == type || 2 == type) {
    color_mapper_ = mapper;
  } else if (1 == type) {
    vertex_mapper_ = mapper;
  }
}/// Operation::Operation

void Relation::add(const size_t i, const size_t j, const int type, const std::vector<size_t>& mapper, const std::vector<size_t>& imapper) {
  if (successors_.count(i)) {
    successors_[i].emplace_back(j);
  } else {
    successors_[i] = std::vector<size_t>({j});
  }
  if (predecessors_.count(j)) {
    predecessors_[j].emplace_back(i);
  } else {
    predecessors_[j] = std::vector<size_t>({i});
  }
  arcs_[std::pair<size_t, size_t>({i, j})] = Operation(type, mapper);
  arcs_[std::pair<size_t, size_t>({j, i})] = Operation(type, imapper);
}/// RelationManager::add

}/// namespace PlanarGraphColoring
