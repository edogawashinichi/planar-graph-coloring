/// digraph_searcher_result.cxx

#include "digraph_searcher_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void DigraphSearcherResult::appendWeakComponent(const size_t vertex) {
  weak_component_.append(vertex);
}/// DigraphSearcherResult::appendWeakComponent

void DigraphSearcherResult::extendWeakComponent(const size_t vertex) {
  weak_component_.extend(vertex);
}/// DigraphSearcherResult::extendWeakComponent

size_t DigraphSearcherResult::weakComponentSize() const {
  return weak_component_.size();
}/// DigraphSearcherResult::size

size_t DigraphSearcherResult::weakComponentSize(const size_t index) const {
  return weak_component_.size(index);
}/// DigraphSearcherResult::weakComponentSize

size_t DigraphSearcherResult::getWeakComponent(const size_t i, const size_t j) const {
  return weak_component_.get(i, j);
}/// DigraphSearcherResult::weakComponentSize

void DigraphSearcherResult::show() const {
  if (!PGC__DEBUG_MODE) return;
  PGC__SHOW_ENDL("weak component:")
  weak_component_.show();
}/// DigraphSearcherResult::show

}/// namespace PlanarGraphColoring
