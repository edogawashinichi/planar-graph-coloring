/// color_result.cxx

#include "color_result.h"
#include "naive_color_representation.h"
#include <iostream>

namespace PlanarGraphColoring {

ColorResult::ColorResult() {
  colors_.clear();
}/// ColorResult::ColorResult 

ColorResult::~ColorResult() {
  for (size_t i = 0; i < colors_.size(); ++i) {
    if (nullptr == colors_[i]) continue;
    delete colors_[i];
    colors_[i] = nullptr;
  }
  colors_.clear();
}/// ColorResult::~ColorResult

std::vector<size_t> ColorResult::getInfo(const size_t index) const {
  /// no safety check
  return colors_[index]->getVector();
}/// ColorResult::getInfo

std::vector<size_t> ColorResult::getInfo(const size_t index, const size_t length) const {
  /// no safety check
  const auto& whole = colors_[index]->getVector();
  return std::vector<size_t>(whole.begin(), whole.begin() + length);
}/// ColorResult::getInfo

void ColorResult::append(const std::vector<size_t>& color) {
  /// currently realized by NaiveColorRepresention
  ColorRepresentation* p = new NaiveColorRepresentation();
  colors_.emplace_back(p);
  for (size_t i = 0; i < color.size(); ++i) {
    colors_.back()->set(i, color[i]);
  }
}/// ColorResult::append

void ColorResult::show() const {
  for (size_t i = 0; i < colors_.size(); ++i) {
    std::cout << i << "th: ";
    colors_[i]->show();
  }
}/// ColorResult::show

void ColorResult::show(const size_t n) const {
  std::cout << "size: " << n << "/" << colors_.size() << "\n";
  size_t k = 0;
  for (size_t i = 0; i < colors_.size(); ++i) {
    if (!colors_[i]->valid()) continue;
    if (k++ >= n) break;
    std::cout << i << "th: ";
    colors_[i]->show();
  }
}/// ColorResult::show

}/// PlanarGraphColoring
