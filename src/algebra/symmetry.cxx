/// symmetry.cxx

#include "symmetry.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

Transformation::Transformation(const std::vector<size_t>& trans) {
  trans_ = trans;
}/// Transformation::Transformation

std::vector<size_t> Transformation::inverse() const {
  std::vector<size_t> res(trans_.size(), 0);
  for (size_t i = 0; i < trans_.size(); ++i) {
    res[trans_[i]] = i;
  }
  return res;
}/// Transformation::inverse

VertexSymmetry::VertexSymmetry(const std::vector<std::vector<size_t>>& mappers) {
  this->set(mappers);
}/// VertexSymmetry::VertexSymmetry

void VertexSymmetry::set(const std::vector<std::vector<size_t>>& mappers) {
  mappers_.reserve(sizeof(mappers) / sizeof(size_t));
  mappers_.insert(mappers_.end(), mappers.begin(), mappers.end());
  /*mappers_ = mappers;*/
}/// VertexSymmetry::set

std::vector<size_t> VertexSymmetry::get(const size_t index) const {
  return mappers_[index];
}/// VertexSymmetry::get

void VertexSymmetry::show() const {
  for (size_t i = 0; i < mappers_.size(); ++i) {
    const auto& mapper = mappers_[i];
    std::cout << i << "th:  ";
    PGC__SHOW_VEC_WITH_INDEX(mapper)
  }
}/// VertexSymmetry::show

}/// PlanarGraphColoring
