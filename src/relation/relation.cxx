/// relation.cxx

#include "relation.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring{

Relation::Relation(const size_t from, const size_t to, const size_t type, const std::vector<size_t>& mapper) {
  from_ = from;
  to_ = to;
  type_ = type;
  mapper_ = mapper;
}/// Relation::Relation

void Relation::show() const {
  if (!PGC__DEBUG_MODE) return;
  std::cout << from_ << "->" << to_ << " ";
  switch (type_) {
    case 0:
      std::cout << "vertex ";
      break;
    case 1:
      std::cout << "color ";
      break;
    default:
      std::cout << "kempe ";
  }
  PGC__SHOW_VEC_WITH_INDEX(mapper_);
}/// Relation::show

}/// namespace PlanarGraphColoring
