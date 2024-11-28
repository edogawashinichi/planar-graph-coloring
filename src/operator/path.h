/// path.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

struct Path {
  Path();
  Path(const std::vector<size_t>& v);
  void show() const;
  void clear();
  size_t first() const;
  size_t last() const;
  std::vector<size_t> vertices_;
};/// struct Path

}/// namespace PlanarGraphColoring
