/// graph.h

/// undirected simple graph for coloring

#pragma once

#include <vector>
#include <unordered_map>

namespace PlanarGraphColoring {

class Graph {
protected:
  size_t n_;/// number of vertices indexed from 0 to n-1
  std::unordered_map<size_t, std::vector<size_t>> neighbors_;

public:
  Graph() = default;
  Graph(const size_t n, const std::vector<std::vector<size_t>>& edges);
  virtual void show() const;
  std::vector<size_t> getNeighbors(const size_t vertex) const;
  inline size_t size() const {
    return n_;
  }
};/// class Graph

}/// namespace PlanarGraphColoring
