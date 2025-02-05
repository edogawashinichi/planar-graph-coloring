/// neighborhood.h

#pragma once

#include "ring.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

template <size_t K>
class Neighborhood : public Ring {
public:
  inline Neighborhood() {
    k_ = K;
    n_ = K + 1;
    const VII& edges = this->getEdges();
    for (const auto& edge : edges) {
      Graph::addEdge(edge.first, edge.second);
    }/// for
  }/// Neighborhood

  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "neighborhood size: " << k_ << "\n";
    Ring::show(cout);
  }/// show
  virtual VII getEdges() const override {
    VII res;
    for (int i = 0; i <= static_cast<int>(k_) - 2; ++i) {
      res.emplace_back(std::pair<size_t, size_t>({static_cast<size_t>(i), static_cast<size_t>(i) + 1}));
    }/// for
    res.push_back(std::pair<size_t, size_t>({k_ - 1, 0}));
    for (size_t i = 0; i < k_; ++i) {
      res.emplace_back(std::pair<size_t, size_t>({i, k_}));
    }/// for
    dict_sort(res);
    return res;
  }/// getEdges
};/// class Neighborhood

}/// namespace PlanarGraphColoring
