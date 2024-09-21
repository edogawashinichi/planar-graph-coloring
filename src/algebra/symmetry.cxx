/// symmetry.cxx

#include "symmetry.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

VertexSymmetry::VertexSymmetry(const std::vector<std::vector<int>>& mappers) {
  this->set(mappers);
}/// VertexSymmetry::VertexSymmetry

void VertexSymmetry::set(const std::vector<std::vector<int>>& mappers) {
  mappers_.reserve(sizeof(mappers) / sizeof(int));
  mappers_.insert(mappers_.end(), mappers.begin(), mappers.end());
  /*mappers_ = mappers;*/
}/// VertexSymmetry::set

std::vector<int> VertexSymmetry::get(const size_t index) const {
  return mappers_[index];
}/// VertexSymmetry::get

void VertexSymmetry::show() const {
  for (size_t i = 0; i < mappers_.size(); ++i) {
    const auto& mapper = mappers_[i];
    std::cout << i << "th:  ";
    PGC__SHOW_VEC_WITH_INDEX__(mapper)
  }
}/// VertexSymmetry::show

}/// PlanarGraphColoring
