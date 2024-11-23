/// mapper.cxx

#include "mapper.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

size_t Mapper::get(const size_t i, const size_t j) const {
  /// assuming: contains
  return plane2line_.at(std::pair<size_t, size_t>({i, j}));
}/// Mapper::get

void Mapper::insert(const size_t i, const size_t j, const size_t k) {
  this->insert(i, std::pair<size_t, size_t>({j, k}));
}/// Mapper::insert

void Mapper::insert(const size_t i, const std::pair<size_t, size_t>& p) {
  plane2line_[p] = i;
  line2plane_[i] = p;
}/// Mapper::insert

void Mapper::show(const size_t n) const {
  if (!PGC__DEBUG_MODE) return;
  std::cout << "size: " << n << "/" << line2plane_.size() << "\n";
  size_t i = 0;
  for (const auto& kv : line2plane_) {
    if (i >= n) break;
    std::cout << (i++) << "th: ";
    std::cout << kv.first << "->" << "(" << kv.second.first << "," << kv.second.second << ")\n";
  }
}/// Mapper::show

}/// namespace PlanarGraphColoring
