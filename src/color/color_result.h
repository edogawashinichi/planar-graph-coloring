/// color_result.h

#pragma once

#include "color_representation.h"
#include <vector>

namespace PlanarGraphColoring {

class ColorResult {
protected:
  std::vector<ColorRepresentation*> colors_;
public:
  ColorResult();
  void append(const std::vector<int>& color);
  inline size_t size() const {
    return colors_.size();
  }
  std::vector<int> getInfo(const size_t index) const;
  inline ColorRepresentation* get(const size_t index) {
    return colors_[index];
  }
  inline ColorRepresentation* getConst(const size_t index) const {
    return colors_[index];
  }
  inline std::vector<ColorRepresentation*>& get() {
    return colors_;
  }
  void show() const;
  void show(const size_t n) const;
  ~ColorResult();
};/// class ColorResult

}/// namespace PlanarGraphColoring
