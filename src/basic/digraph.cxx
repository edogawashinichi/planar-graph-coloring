/// digraph.cxx

#include "digraph.h"
#include "notation.h"

#define INSERT(some, u, v) \
if (some##_.count(u)) {\
  some##_[u].emplace_back(v);\
} else {\
  some##_.insert({u, {v}});\
}

namespace PlanarGraphColoring {

void Digraph::append(const size_t i, const size_t j) {
  INSERT(successors, i, j)
  INSERT(predecessors, j, i)
}/// void Digraph::append

Digraph::Digraph(const size_t n) {
  n_ = n;
}/// Digraph::Digraph

Digraph::Digraph(const size_t n, const std::vector<std::vector<size_t>>& edges) {
  n_ = n;
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    INSERT(successors, u, v)
    INSERT(predecessors, v, u)
  }
}/// Digraph::Digraph

size_t Digraph::arcs() const {
  size_t res = 0;
  for (const auto& kv : predecessors_) {
    res += kv.second.size();
  }
  return res;
}/// Digraph::arcs

void Digraph::show() const {
  if (!PGC__DEBUG_MODE) return;
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

void Digraph::show(const size_t n) const {
  if (!PGC__DEBUG_MODE) return;
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "predecessors:\n";
  size_t i = 0;
  for (const auto& kv : predecessors_) {
    if (i++ >= n) break;
    std::cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
  std::cout << "successors:\n";
  i = 0;
  for (const auto& kv : successors_) {
    if (i++ >= n) break;
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
