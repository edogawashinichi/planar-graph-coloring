/// graph.cxx

#include "graph.h"
#include "notation.h"
#include "math.h"

#define INSERT(u, v) \
if (neighbors_.count(u)) {\
  neighbors_[u].push_back(v);\
} else {\
  neighbors_.insert({u, {v}});\
}

namespace PlanarGraphColoring {

std::vector<std::vector<size_t>> Graph::getNeighborsInfo() const {
  DEBUG_START(Graph::getNeighborsInfo)
  std::vector<std::vector<size_t>> res(n_, std::vector<size_t>());
  for (const auto& kv : neighbors_) {
    std::vector<size_t> vec(kv.second);
    std::sort(vec.begin(), vec.end());
    res[kv.first] = vec;
  }/// for
  //dict_sort(res); /* WARNING: radix sort */
  DEBUG_END(Graph::getNeighborsInfo)
  return res;
}/// Graph::getNeighborsInfo

std::vector<std::vector<size_t>> Graph::getEdges() const {
  std::vector<std::vector<size_t>> res;
  for (const auto& kv : neighbors_) {
    const size_t u = kv.first;
    for (const auto& v : kv.second) {
      if (u >= v) continue;
      res.emplace_back(std::vector<size_t>({u, v}));
    }/// v
  }/// for kv
  return res;
}/// Graph::getEdges

void Graph::clear() {
  n_ = 0;
  neighbors_.clear();
}/// Graph::clear

void Graph::insert(const size_t u, const size_t v) {
  if (neighbors_.count(u)) {
    neighbors_[u].emplace_back(v);
  } else {
    neighbors_[u] = std::vector<size_t>({v});
  }
}/// Graph::insert

Graph::Graph(const std::vector<std::vector<size_t>>& edges) {
  n_ = 0;
  neighbors_.clear();
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    n_ = max(n_, u + 1, v + 1);
    INSERT(u, v)
    INSERT(v, u)
  }
}/// Graph::Graph

Graph::Graph(const size_t n, const std::vector<std::vector<size_t>>& edges) {
  n_ = n;
  neighbors_.clear();
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    INSERT(u, v)
    INSERT(v, u)
  }
}/// Graph::Graph

void Graph::show() const {
  TEST_INFO
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "neighbors:\n";
  const std::vector<std::vector<size_t>> neighbors(this->getNeighborsInfo());
  for (size_t i = 0; i < neighbors.size(); ++i) {
    const auto& vec = neighbors[i];
    std::cout << i << ": { ";
    for (const auto v : vec) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
}/// Graph::show

void Graph::show(const size_t n) const {
  TEST_INFO
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "neighbors:\n";
  size_t i = 0;
  for (const auto& kv : neighbors_) {
    if (i++ >= n) break;
    std::cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
}/// Graph::show

std::vector<size_t> Graph::getNeighbors(const size_t vertex) const{
  return neighbors_.count(vertex) ? neighbors_.at(vertex) : std::vector<size_t>();
}/// Graph::getNeighbors

}/// namespace PlanarGraphColoring
