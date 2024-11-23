/// directed_path_result.cxx

#include "directed_path_result.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

DirectedPath DirectedPathResult::getDirectedPath(const size_t i, const size_t j) const {
  if (paths_.count(std::pair<size_t, size_t>({i, j}))) return paths_.at(std::pair<size_t, size_t>({i, j}));
  return DirectedPath();
}/// DirectedPathResult::getDirectedPath

void DirectedPathResult::clear() {
  paths_.clear();
}/// DirectedPathResult::clear

void DirectedPathResult::insert(const DirectedPath& path) {
  /// assuming: path not empty
  this->insert(path.first(), path.last(), path);
}/// DirectedPathResult::insert

void DirectedPathResult::insert(const size_t i, const size_t j, const DirectedPath& path) {
  paths_[std::pair<size_t, size_t>({i, j})] = path;
}/// DirectedPathResult::insert

void DirectedPathResult::show() const {
  TEST_INFO
  std::cout << "size: " << paths_.size() << "\n";
  const std::vector<std::vector<size_t>> res(this->getPathsInfo());
  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << i << "th:  ";
    PGC__SHOW_VEC_WITH_ARROW(res[i])
  }
}/// DirectedPathResult::show

void DirectedPathResult::show(const size_t vertex) const {
  TEST_INFO
  const std::vector<DirectedPath>& paths = this->getPaths(vertex);
  std::cout << "size: " << paths.size() << "\n";
  for (size_t i = 0; i < paths.size(); ++i) {
    std::cout << i << "th:  ";
    paths[i].show();
  }
}/// DirectedPathResult::show

std::vector<DirectedPath> DirectedPathResult::getPaths(const size_t vertex) const {
  std::vector<DirectedPath> res;
  for (const auto& kv : paths_) {
    if (kv.first.first != vertex) continue;
    res.emplace_back(kv.second);
    /// vec.emplace_back(obj):
    //    0. obj --deepcopy--> anonym
    //    1. anonym --movecopy--> vec.back
    /// vec.emplace_back(std::move(obj)):
    //    0. obj --movecopy--> anonym
    //    1. anonym --movecopy--> vec.back
    /// vec.push_back(obj):
    //    0. obj --deepcopy--> anonym
    //    1. anonym --deepcopy--> vec.back
    /// vec.push_back(std::move(obj)):
    //    0. obj --movecopy--> anonym
    //    1. anonym --deepcopy--> vec.back
  }
  return res;
}/// DirectedPathResult::getPaths

std::vector<std::vector<size_t>> DirectedPathResult::getPathsInfo() const {
  std::vector<std::vector<size_t>> res;
  for (const auto& kv : paths_) {
    res.emplace_back(kv.second.vertices_);
  }
  dict_sort(res);
  return res;
}/// DirectedPathResult::getPathsInfo

}/// namespace PlanarGraphColoring
