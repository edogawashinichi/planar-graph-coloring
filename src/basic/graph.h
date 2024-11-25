/// graph.h

/// undirected simple graph for coloring
/// assuming: graph is edge-symmetry

#pragma once

#include "structure.h"
#include <vector>
#include <unordered_map>

namespace PlanarGraphColoring {

class Graph : public Structure {
protected:
  size_t n_;/// number of vertices indexed from 0 to n-1
  std::unordered_map<size_t, std::vector<size_t>> neighbors_;

public:
  Graph() = default;
  Graph(const std::vector<std::vector<size_t>>& edges);
  Graph(const size_t n, const std::vector<std::vector<size_t>>& edges);
  virtual void show() const override;
  virtual void show(const size_t n) const override;
  void clear();
  inline void setSize(const size_t n) {
    n_ = n;
  }
  void insert(const size_t u, const size_t v);
  std::vector<size_t> getNeighbors(const size_t vertex) const;
  inline size_t size() const {
    return n_;
  }
  std::vector<std::vector<size_t>> getNeighborsInfo() const;
  std::vector<std::vector<size_t>> getEdges() const;
};/// class Graph

}/// namespace PlanarGraphColoring
