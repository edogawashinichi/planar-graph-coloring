/// relation.cxx

#include "relation.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void Mapper::show(const size_t n) const {
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

Operation::Operation(const int type, const std::vector<int>& mapper) {
  type_ = type;
  if (0 == type || 2 == type) {
    color_mapper_ = mapper;
  } else if (1 == type) {
    vertex_mapper_ = mapper;
  }
}/// Operation::Operation

}/// namespace PlanarGraphColoring
