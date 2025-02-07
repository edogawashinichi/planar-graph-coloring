/// acc_coloring_result.h

#pragma once

#include "coloring_result.h"
#include "../basic/hash.h"

namespace PlanarGraphColoring {

class AccColoringResult {
public:
  inline AccColoringResult() = delete;
  inline AccColoringResult(const ColoringResult& colorings){
    for (size_t i = 0; i < colorings.size(); ++i) {
      coloring2index_[colorings.getConst(i).getData()] = i;
    }
  }/// constructor
  inline int find(const Coloring& coloring) const {
    return this->find(coloring.getData());
  }/// find
  inline int find(const VI& coloring) const {
    return coloring2index_.count(coloring) ? coloring2index_.at(coloring) : -1;
  }/// find
protected:
  std::unordered_map<VI, size_t, vi_hash> coloring2index_;
};/// class AccColoringResult

}/// namespace PlanarGraphColoring
