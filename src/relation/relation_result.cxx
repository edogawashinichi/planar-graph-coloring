/// relation_result.cxx

#include "relation_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void RelationResult::show(const size_t n) const {
  if (!PGC__DEBUG_MODE) return;
  std::cout << "size: " << n << "/" << relations_.size() << "\n";
  for (size_t i = 0; i < n && i < relations_.size(); ++i) {
    std::cout << i << "th: ";
    relations_[i].show();
  }
}/// RelationResult::show

}/// namespace PlanarGraphColoring
