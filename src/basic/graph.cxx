/// graph.cxx

#include "graph.h"
#include <iostream>

#define __INSERT(u, v) \
if (neighbors_.count(u)) {\
  neighbors_[u].push_back(v);\
} else {\
  neighbors_.insert({u, {v}});\
}

namespace PlanarGraphColoring {

Graph::Graph(const size_t n, const std::vector<std::vector<int>>& edges) {
  n_ = n;
  for (const auto& edge : edges) {
    const int u = edge[0];
    const int v = edge[1];
    __INSERT(u, v)
    __INSERT(v, u)
  }
}/// Graph::Graph

void Graph::show() const {
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "neighbors:\n";
  for (const auto& kv : neighbors_) {
    std::cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
}/// Graph::show

std::vector<int> Graph::getNeighbors(const int vertex) const{
  /// no safety check
  return neighbors_.at(vertex);
}/// Graph::getNeighbors

}/// namespace PlanarGraphColoring
