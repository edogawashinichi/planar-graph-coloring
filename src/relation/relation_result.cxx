/// relation_result.cxx

#include "relation_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

Relation RelationResult::get(const size_t index) const {
  /// assuming: 0 <= index < size
  return relations_[index];
}/// RelationResult::get

void RelationResult::show(const size_t n) const {
  TEST_INFO
  std::cout << "size: " << n << "/" << relations_.size() << "\n";
  for (size_t i = 0; i < n && i < relations_.size(); ++i) {
    std::cout << i << "th: ";
    relations_[i].show();
  }
}/// RelationResult::show

}/// namespace PlanarGraphColoring
