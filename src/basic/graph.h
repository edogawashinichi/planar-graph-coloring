/// graph.h

/// undirected simple graph for coloring

#pragma once

#include "structure.h"
#include "notation.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class Graph : public Structure {
protected:
  size_t n_;/// number of vertices indexed from 0 to n-1
  std::unordered_map<size_t, std::vector<size_t>> neighbors_;
public:
  virtual bool isPlanarGraph() const;
  virtual bool isRing(const size_t k) const;
public:
  void deleteVertex(const size_t vertex, const bool resize = false);
  void deleteVertices(const VI& vertices, const bool resize = false);
  void deleteVerticesAtLeast(const size_t vertex, const bool resize = true);

public:
  Graph() = default;
  Graph(const Graph& rhs);
  Graph(Graph&& rhs);
  Graph& operator=(const Graph& rhs);
  Graph& operator=(Graph&& rhs);
  Graph(const std::vector<std::vector<size_t>>& edges);
  Graph(const size_t n, const std::vector<std::vector<size_t>>& edges);
  virtual void show() const override;
  virtual void show(const size_t n) const override;
  void clear();
  void setSize(const size_t n);
  void insert(const size_t u, const size_t v);
  bool contain(const size_t u, const size_t v) const;
  std::vector<size_t> getNeighbors(const size_t vertex) const;
  inline size_t size() const {
    return n_;
  }
  const std::vector<std::vector<size_t>> getNeighborsInfo() const;
  virtual VII getEdges() const;
  bool containEdge(const size_t i, const size_t j) const;
  void addEdge(const size_t i, const size_t j);
  void addUniNeighbor(const size_t i, const size_t j);
};/// class Graph

}/// namespace PlanarGraphColoring
