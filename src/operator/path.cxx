/// path.cxx

#include "path.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

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
  PGC__SHOW_VEC_WITH_INDEX(vertices_)
}/// Path::show

}/// namespace PlanarGraphColoring
