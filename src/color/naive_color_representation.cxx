/// naive_color_representation.cxx

#include "naive_color_representation.h"
#include "../basic/notation.h"
#include <vector>
#include <algorithm>

namespace PlanarGraphColoring {

NaiveColorRepresentation::NaiveColorRepresentation() {
  index2color_.clear();
}/// NaiveColorRepresentation::NaiveColorRepresentation

NaiveColorRepresentation::NaiveColorRepresentation(const std::vector<size_t>& colors) {
  for (size_t i = 0; i < colors.size(); ++i) {
    index2color_[i] = colors[i];
  }
}/// NaiveColorRepresentation::NaiveColorRepresentation

size_t NaiveColorRepresentation::size() const {
  return index2color_.size();
}/// NaiveColorRepresentation::size

size_t NaiveColorRepresentation::get(const size_t index) const {
  /// no safety check to ensure performance
  return index2color_.count(index) ? index2color_.at(index) : -1;
}/// NaiveColorRepresentation::get

std::vector<size_t> NaiveColorRepresentation::getVector() const {
  size_t max = 0;
  for (const auto& kv : index2color_) {
    max = max > kv.first ? max : kv.first;
  }
  std::vector<size_t> res(max + 1, 0);
  for (const auto& kv : index2color_) {
    res[kv.first] = kv.second;
  }
  return res;
}/// NaiveColorRepresentation::getVector

void NaiveColorRepresentation::set(const size_t index, const size_t color) {
  /// no safety check to ensure performance
  index2color_[index] = color;
}/// NaiveColorRepresentation::set

void NaiveColorRepresentation::reset(const size_t index) {
  index2color_[index] = UNDEF_COLOR;
}/// NaiveColorRepresentation::reset

void NaiveColorRepresentation::show() const {
  if (!PGC__DEBUG_MODE) return;
  std::vector<std::pair<size_t, size_t>> colors;
  for (const auto& kv : index2color_) {
    //std::cout << kv.first << ":" << kv.second << " ";
    colors.emplace_back(kv);
  }
  auto cmp = [](const auto& left, const auto& right) -> bool {
    return left.first < right.first;
  };
  std::sort(colors.begin(), colors.end(), cmp);
  PGC__SHOW_VII_WITH_COLOR_SEP(colors, 6, PURPLE, CYAN)
}/// NaiveColorRepresentation::show

bool NaiveColorRepresentation::valid() const {
  return true;
  for (const auto& kv : index2color_) {
    if (kv.second < 0) return false;
  }
  return true;
}/// NaiveColorRepresentation::valid

}/// namespace PlanarGraphColoring
