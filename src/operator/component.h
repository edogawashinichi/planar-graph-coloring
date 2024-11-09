/// component.h

#pragma once

#include "../basic/notation.h"
#include <vector>

namespace PlanarGraphColoring {

class Component {
public:
  inline virtual void show() const {
    if (!PGC__DEBUG_MODE) return;
    PGC__SHOW_VVI_WITH_INDEX(c_)
  }
  inline size_t size() const {
    return c_.size();
  }
  inline size_t size(const size_t index) const {
    return c_[index].size();
  }
  inline size_t get(const size_t i, const size_t j) const {
    return c_[i][j];
  }
protected:
  std::vector<std::vector<size_t>> c_;
};/// class Component

}/// namespace PlanarGraphColoring
