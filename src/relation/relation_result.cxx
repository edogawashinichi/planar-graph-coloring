/// relation_result.cxx

#include "relation_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

Relation RelationResult::get(const size_t index) const {
  /// assuming: 0 <= index < size
  return relations_[index];
}/// RelationResult::get

void RelationResult::show(std::ostream& cout, const size_t n) const {
  TEST_INFO
  cout << "size: " << n << "/" << relations_.size() << "\n";
  for (size_t i = 0; i < n && i < relations_.size(); ++i) {
    cout << i << "th: ";
    relations_[i].show(cout);
    VERBOSE << " after relation i show\n";
  }
}/// RelationResult::show

}/// namespace PlanarGraphColoring
