/// digraph_searcher_result.cxx

#include "digraph_searcher_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

DirectedPathResult* DigraphSearcherResult::getDirectedPathResult() {
  return &directed_path_result_;
}/// DigraphSearcherResult::getDirectedPathResult

void DigraphSearcherResult::appendDirectedPath(const DirectedPath& path) {
  directed_path_result_.insert(path);
}/// DigraphSearcherResult::appendDirectedPath

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
  TEST_INFO
  PGC__SHOW_ENDL("weak component:")
  weak_component_.show();
  PGC__SHOW_ENDL("directed paths:")
  directed_path_result_.show();
}/// DigraphSearcherResult::show

}/// namespace PlanarGraphColoring
