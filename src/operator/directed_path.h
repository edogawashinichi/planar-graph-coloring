/// directed_path.h

#pragma once

#include "path.h"

namespace PlanarGraphColoring {

struct DirectedPath : public Path {
  DirectedPath() = default;
  DirectedPath(const std::vector<size_t>& v) : Path(v) {}
};/// struct DirectedPath

}/// namespace PlanarGraphColoring
