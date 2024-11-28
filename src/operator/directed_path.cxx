/// directed_path.cxx

#include "directed_path.h"

namespace PlanarGraphColoring {

DirectedPath::DirectedPath() : Path() {}

DirectedPath::DirectedPath(const DirectedPath& rhs) {
  vertices_ = rhs.vertices_;
}/// DirectedPath::DirectedPath

DirectedPath::DirectedPath(DirectedPath&& rhs) {
  vertices_.swap(rhs.vertices_);
}/// DirectedPath::DirectedPath

DirectedPath& DirectedPath::operator=(const DirectedPath& rhs) {
  vertices_ = rhs.vertices_;
  return *this;
}/// DirectedPath::operator=

}/// namespace PlanarGraphColoring
