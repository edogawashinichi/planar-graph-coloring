/// disjoint_set.h

#pragma once

#include <vector>
#include <set>

namespace PlanarGraphColoring {

class DisjointSet {
public:
  DisjointSet(const int n);
  void unite(const int i, const int j);
  int find(int i);
  inline int n() const {
    return n_;
  }
  void showParent() const;
  std::set<int> getRoots();
protected:
  std::vector<int> parent_;
  std::vector<int> rank_;
  std::vector<int> size_;
  int n_;
};/// class DisjointSet

}/// namespace PlanarGraphColoring
