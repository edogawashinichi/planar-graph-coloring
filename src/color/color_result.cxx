/// color_result.cxx

#include "color_result.h"
#include "naive_color_representation.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

ColorResult::ColorResult() {
  colors_.clear();
  DEBUG << "ColorResult constructor\n";
}/// ColorResult::ColorResult 

ColorResult::ColorResult(const ColorResult& rhs) {
  DEBUG << "start ColorResult deepcopy\n";
  DEBUG << "rhs:\n";
  if (PGC__DEBUG_MODE) rhs.show();
  for (size_t i = 0; i < rhs.colors_.size(); ++i) {
    DEBUG << i << "th:\n";
    NaiveColorRepresentation* ptr = dynamic_cast<NaiveColorRepresentation*>(rhs.colors_[i]);
    ColorRepresentation* p = new NaiveColorRepresentation(*ptr);
    this->colors_.emplace_back(p);
    if (PGC__DEBUG_MODE) PGC__SHOW_2VAR(ptr, p);
  }
  DEBUG << "end ColorResult deepcopy\n";
}/// ColorResult::ColorResult

ColorResult::ColorResult(ColorResult&& rhs) {
  DEBUG << "start ColorResult movecopy\n";
  for (size_t i = 0; i < rhs.colors_.size(); ++i) {
    DEBUG << i << "th:\n";
    ColorRepresentation* ptr = rhs.colors_[i];
    rhs.colors_[i] = nullptr;
    this->colors_.emplace_back(ptr);
  }
  DEBUG << "end ColorResult movecopy\n";
}/// ColorResult::ColorResult

ColorResult::~ColorResult() {
  DEBUG << "start ColorResult destructor\n";
  for (size_t i = 0; i < colors_.size(); ++i) {
    DEBUG << i << "th:\n";
    if (nullptr == colors_[i]) continue;
    DEBUG << "  not nullptr\n";
    DEBUG << " address: " << colors_[i] << "\n";
    delete colors_[i];
    DEBUG << "  delete success!\n";
    colors_[i] = nullptr;
  }
  colors_.clear();
  DEBUG << "end ColorResult destructor\n";
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
  /// TODO
  /// memory leak risk
  ColorRepresentation* p = new NaiveColorRepresentation();
  colors_.emplace_back(p);
  for (size_t i = 0; i < color.size(); ++i) {
    colors_.back()->set(i, color[i]);
  }
}/// ColorResult::append

void ColorResult::show() const {
  if (!PGC__DEBUG_MODE && !PGC__INFO_MODE) return;
  for (size_t i = 0; i < colors_.size(); ++i) {
    std::cout << i << "th: ";
    colors_[i]->show();
  }
}/// ColorResult::show

void ColorResult::show(const size_t n) const {
  if (!PGC__DEBUG_MODE && !PGC__INFO_MODE) return;
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
