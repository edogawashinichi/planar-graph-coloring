/// disjoint_set.cpp

#include "disjoint_set.h"

#include <iostream>

namespace PlanarGraphColoring {

DisjointSet::DisjointSet(const int n) {
  parent_.resize(n);
  parent_.assign(parent_.size(), -1);
  rank_.resize(n);
  rank_.assign(rank_.size(), 0);
  size_.resize(n);
  size_.assign(size_.size(), 1);
  n_ = n;
}/// DisjointSet::DisjointSet

void DisjointSet::showParent() const {
  for (int i = 0; i < parent_.size(); ++i) {
    std::cout << i << ":" << parent_[i] << " ";
  }
  std::cout << "\n";
}/// DisjointSet::showParent

std::set<int> DisjointSet::getRoots() {
  std::set<int> res;
  for (int i = 0; i < parent_.size(); ++i) {
    res.insert(find(i));
  }
  return res;
}/// DisjointSet::getRoots

void DisjointSet::unite(const int i, const int j) {
  const int ri = find(i);
  const int rj = find(j);
  if (ri == rj) return;
  if (ri==3&&rj==8) std::cout << "disjoint set unite i:ri=" << i << ":" << ri << " j:rj=" << j << ":" << rj << "\n";
  if (rank_[ri] < rank_[rj]) {
    parent_[ri] = rj;
    size_[rj] += size_[ri];
  } else if (rank_[ri] > rank_[rj]) {
    parent_[rj] = ri;
    size_[ri] += size_[rj];
  } else { /* rank_[ri]==rank_[rj] */
    if (size_[ri] >= size_[rj]) { /* bring unconvinience if using > */
      parent_[rj] = ri;
      rank_[ri] += 1;
      size_[ri] += size_[rj];
    } else {
      parent_[ri] = rj;
      rank_[rj] += 1;
      size_[rj] += size_[ri];
    }
  } /* rank_[ri]==rank_[rj] */
  --n_;
}/// DisjointSet::unite

int DisjointSet::find(int i) {
  if (-1 == parent_[i]) return i;
  parent_[i] = find(parent_[i]);
  return parent_[i];
}/// DisjointSet::find

}/// namespace PlanarGraphColoring
