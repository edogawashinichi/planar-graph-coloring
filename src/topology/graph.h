/// graph.h
// undirected simple graph for coloring

#pragma once

#include <vector>
#include <unordered_map>

namespace PlanarGraphColoring {

class Graph {
protected:
  size_t n_;/// number of vertices indexed from 0 to n-1
  std::unordered_map<int, std::vector<int>> neighbors_;

public:
  Graph() = default;
  Graph(const size_t n, const std::vector<std::vector<int>>& edges);
  virtual void show() const;
  std::vector<int> getNeighbors(const int vertex) const;
  inline size_t size() const {
    return n_;
  }
};/// class Graph

}/// namespace PlanarGraphColoring
