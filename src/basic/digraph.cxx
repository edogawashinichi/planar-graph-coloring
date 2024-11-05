/// digraph.cxx

#include "digraph.h"
#include <iostream>

#define __INSERT(some, u, v) \
if (some##_.count(u)) {\
  some##_[u].emplace_back(v);\
} else {\
  some##_.insert({u, {v}});\
}

namespace PlanarGraphColoring {

Digraph::Digraph(const size_t n, const std::vector<std::vector<size_t>>& edges) {
  n_ = n;
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    __INSERT(successors, u, v)
    __INSERT(predecessors, v, u)
  }
}/// Digraph::Digraph

void Digraph::show() const {
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "predecessors:\n";
  for (const auto& kv : predecessors_) {
    std::cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
  std::cout << "successors:\n";
  for (const auto& kv : successors_) {
    std::cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
}/// Digraph::show

std::vector<size_t> Digraph::getPredecessors(const size_t vertex) const{
  return predecessors_.count(vertex) ? predecessors_.at(vertex) : std::vector<size_t>();
}/// Digraph::getPredecessors

std::vector<size_t> Digraph::getSuccessors(const size_t vertex) const{
  return successors_.count(vertex) ? successors_.at(vertex) : std::vector<size_t>();
}/// Digraph::getSuccessors

}/// namespace PlanarGraphColoring
