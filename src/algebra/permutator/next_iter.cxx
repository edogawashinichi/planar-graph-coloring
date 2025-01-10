/// next_iter.cxx

#include "next_iter.h"

namespace PlanarGraphColoring {

VVI NextIter::run(const size_t n) {
  VVI res;
  res.emplace_back(id<size_t>(n));
  while (true) {
    VI next;
    if (!this->run(res.back(), &next)) break;
    res.emplace_back(next);
  }
  return res;
}/// NextIter::run

VI NextIter::run(const size_t n, const size_t i) {
  VVI res;
  res.emplace_back(id<size_t>(n));
  for (size_t j = 0; j < i; ++j) {
    VI next;
    if (!this->run(res.back(), &next)) break;
    res.emplace_back(next);
  }
  return res.back();
}/// NextIter::run

bool NextIter::run(const VI& cur, VI* next) {
  bool res = false;
  VI a(cur);
  const int ascend_max_index = this->ascendMaxIndex(a);
  DEBUG_VAR(ascend_max_index)
  if (ascend_max_index != -1) {
    const size_t min_ascend_index = this->minAscendIndex(a, ascend_max_index);
    DEBUG_VAR(min_ascend_index)
    std::swap(a[ascend_max_index], a[min_ascend_index]);
    std::sort(a.begin() + ascend_max_index + 1, a.end());
    *next = a;
    res = true;
  }/// if
  return res;
}/// NextIter::run

size_t NextIter::minAscendIndex(const VI& a, const size_t ascend_max_index) {
  size_t min_index = ascend_max_index + 1;
  size_t min_value = a[ascend_max_index + 1];
  for (size_t i = ascend_max_index + 2; i < a.size(); ++i) {
    if (a[i] > a[ascend_max_index] && a[i] < min_value) {
      min_value = a[i];
      min_index = i;
    }/// if
  }/// for
  return min_index;
}/// NextIter::minAscendIndex

int NextIter::ascendMaxIndex(const VI& a) {
  int res = -1;
  for (int i = static_cast<int>(a.size()) - 2; i >= 0; --i) {
    if (a[i] < a[i + 1]) {
      res = i;
      break;
    }
  }/// for
  return res;
}/// NextIter::minAscendIndex

}/// namespace PlanarGraphColoring
