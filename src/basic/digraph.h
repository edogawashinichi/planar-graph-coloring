/// digraph.h

/// directed simple graph for relation

#pragma once

#include "structure.h"
#include <vector>
#include <unordered_map>

namespace PlanarGraphColoring {

class Digraph : public Structure {
protected:
  size_t n_;/// number of vertices indexed from 0 to n-1
  std::unordered_map<size_t, std::vector<size_t>> predecessors_;
  std::unordered_map<size_t, std::vector<size_t>> successors_;

public:
  Digraph() = default;
  Digraph(const size_t n); 
  Digraph(const std::vector<std::vector<size_t>>& edges);
  Digraph(const size_t n, const std::vector<std::vector<size_t>>& edges);
  virtual void show() const override;
  virtual void show(const size_t n) const override;
  std::vector<size_t> getPredecessors(const size_t vertex) const;
  std::vector<size_t> getSuccessors(const size_t vertex) const;
  inline size_t size() const {
    return n_;
  }
  size_t arcs() const;/* number of arcs */
  void append(const size_t i, const size_t j);
  inline void setSize(const size_t n) {
    n_ = n;
  }
  inline float weight() const {
    return 1.0f;
  }
};/// class Digraph

}/// namespace PlanarGraphColoring
