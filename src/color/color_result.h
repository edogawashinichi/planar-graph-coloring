/// color_result.h

#pragma once

#include "color_representation.h"
#include <vector>
#include <string>

namespace PlanarGraphColoring {

class ColorResult {
protected:
  std::vector<ColorRepresentation*> colors_;
public:
  ColorResult();
  ColorResult(const ColorResult& rhs);
  ColorResult(ColorResult&& rhs);
  void append(const std::vector<size_t>& color);
  inline size_t size() const {
    return colors_.size();
  }
  inline bool empty() const {
    return colors_.empty();
  }
  inline size_t n() const {
    return colors_.front()->size();
  }
  std::vector<size_t> getInfo(const size_t index) const;
  std::vector<size_t> getInfo(const size_t index, const size_t length) const;
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
  void showWith(const std::string& s, const size_t n) const;
  ~ColorResult();
};/// class ColorResult

}/// namespace PlanarGraphColoring
