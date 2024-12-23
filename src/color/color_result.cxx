/// color_result.cxx

#include "color_result.h"
#include "naive_color_representation.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

int ColorResult::find(const VI& color, const size_t k) const {
  /// assuming: 0 < k < color.size
  /// TODO: basic/hash.h optimize
  int res = -1;
  for (size_t i = 0; i < colors_.size(); ++i) {
    const auto& dest = colors_[i]->getVector();
    if (VI(dest.begin(), dest.begin() + k) != VI(color.begin(), color.begin() + k)) continue;
    res = i;
    break;
  }/// for
  return res;
}/// find

int ColorResult::find(const VI& color) const {
  return this->find(color, color.size());
}/// ColorResult::find

ColorResult::ColorResult() {
  colors_.clear();
  VERBOSE << "ColorResult constructor\n";
}/// ColorResult::ColorResult 

ColorResult::ColorResult(const ColorResult& rhs) {
  VERBOSE_START(ColorResult deepcopy)
  VERBOSE << "rhs:\n";
  VERBOSE_OBJ(rhs)
  for (size_t i = 0; i < rhs.colors_.size(); ++i) {
    VERBOSE << i << "th:\n";
    NaiveColorRepresentation* ptr = dynamic_cast<NaiveColorRepresentation*>(rhs.colors_[i]);
    ColorRepresentation* p = new NaiveColorRepresentation(*ptr);
    this->colors_.emplace_back(p);
    VERBOSE_2VAR(ptr, p)
  }
  VERBOSE_END(ColorResult deepcopy)
}/// ColorResult::ColorResult

ColorResult::ColorResult(ColorResult&& rhs) {
  VERBOSE_START(ColorResult movecopy)
  for (size_t i = 0; i < rhs.colors_.size(); ++i) {
    VERBOSE << i << "th:\n";
    ColorRepresentation* ptr = rhs.colors_[i];
    rhs.colors_[i] = nullptr;
    this->colors_.emplace_back(ptr);
  }
  VERBOSE_END(ColorResult movecopy)
}/// ColorResult::ColorResult

ColorResult::~ColorResult() {
  VERBOSE_START(ColorResult destructor)
  for (size_t i = 0; i < colors_.size(); ++i) {
    VERBOSE << i << "th:\n";
    if (nullptr == colors_[i]) continue;
    VERBOSE << "  not nullptr\n";
    VERBOSE << " address: " << colors_[i] << "\n";
    delete colors_[i];
    VERBOSE << "  delete success!\n";
    colors_[i] = nullptr;
  }
  colors_.clear();
  VERBOSE_END(ColorResult destructor)
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
  /// WARNING: memory leak risk
  /// TODO: pure virtual function allocateMemory()=0
  //        NaiveColorRepresentation::allocateMemory()
  ColorRepresentation* p = new NaiveColorRepresentation();
  colors_.emplace_back(p);
  for (size_t i = 0; i < color.size(); ++i) {
    colors_.back()->set(i, color[i]);
  }
}/// ColorResult::append

void ColorResult::append(const ColorRepresentation& color) {
  /// TODO: get rid of naive
  ColorRepresentation* p = new NaiveColorRepresentation();
  colors_.emplace_back(p);
  for (size_t i = 0; i < color.size(); ++i) {
    colors_.back()->set(i, color.get(i));
  }
}/// ColorResult::append

void ColorResult::show() const {
  TEST_INFO
  for (size_t i = 0; i < colors_.size(); ++i) {
    std::cout << i << "th: ";
    colors_[i]->show();
  }
}/// ColorResult::show

void ColorResult::show(const size_t n) const {
  TEST_INFO
  INFO << "size: " << n << "/" << colors_.size() << "\n";
  size_t k = 0;
  for (size_t i = 0; i < colors_.size(); ++i) {
    if (!colors_[i]->valid()) continue;
    if (k++ >= n) break;
    std::cout << i << "th: ";
    colors_[i]->show();
  }
}/// ColorResult::show

void ColorResult::showWith(const std::string& s, const size_t n) const {
  TEST_INFO
  INFO << "size: " << n << "/" << colors_.size() << "\n";
  size_t k = 0;
  for (size_t i = 0; i < colors_.size(); ++i) {
    if (!colors_[i]->valid()) continue;
    if (k >= n) break;
    if (0 == k) std::cout << i << "th(" << s << "): ";
    else std::cout << i << "th: ";
    colors_[i]->show();
    if (s == "representative") break;
    ++k;
  }
}/// ColorResult::showWith

}/// PlanarGraphColoring
