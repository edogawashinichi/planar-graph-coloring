/// path.cxx

#include "path.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

size_t Path::first() const {
  /// assuming: vertices_ not empty
  return vertices_.front();
}/// Path::first

size_t Path::last() const {
  /// assuming: vertices_ not empty
  return vertices_.back();
}/// Path::last

Path::Path() {
  vertices_.clear();
}/// Path::Path

Path::Path(const std::vector<size_t>& v) : vertices_(v) {
}/// Path::Path

void Path::clear() {
  vertices_.clear();
}/// Path::clear

void Path::show() const {
  TEST_INFO
  PGC__SHOW_VEC_WITH_ARROW(vertices_)
}/// Path::show

}/// namespace PlanarGraphColoring
