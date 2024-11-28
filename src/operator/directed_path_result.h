/// directed_path_result.h

#pragma once

#include "directed_path.h"
#include "../basic/hash.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class DirectedPathResult {
public:
  void insert(const DirectedPath& path);
  void insert(const size_t i, const size_t j, const DirectedPath& path);
  void clear();
  void show() const;
  void show(const size_t vertex) const;
  DirectedPath getDirectedPath(const size_t i, const size_t j) const;
  std::vector<DirectedPath> getPaths(const size_t vertex) const;
  std::vector<std::vector<size_t>> getPathsInfo(const size_t vertex) const;
  std::vector<std::vector<size_t>> getPathsInfo() const;
protected:
  std::unordered_map<std::pair<size_t, size_t>, DirectedPath, pair_hash> paths_;
};/// class DirectedPathResult

}/// namespace PlanarGraphColoring
