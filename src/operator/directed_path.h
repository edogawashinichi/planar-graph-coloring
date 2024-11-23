/// directed_path.h

#pragma once

#include "path.h"

namespace PlanarGraphColoring {

struct DirectedPath : public Path {
  DirectedPath();
  DirectedPath(const DirectedPath& rhs);
  DirectedPath(DirectedPath&& rhs);
  DirectedPath(const std::vector<size_t>& v) : Path(v) {}
  DirectedPath& operator=(const DirectedPath& rhs);
};/// struct DirectedPath

}/// namespace PlanarGraphColoring
