/// johnson_trotter.cxx

#include "johnson_trotter.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

VVI JohnsonTrotter::run(const size_t n) {
  /// TODO: optimize by omitting direction
  DEBUG_START(JohnsonTrotter::run)
  VVI res;
  VI direction(n, 1);/// 1: mobile from right to left
                     /// 0: mobile from left to right
  VI a(id<size_t>(n));/// inplace permutation
  do {
    DEBUG_VAR(res.size())
    DEBUG_VEC(direction)
    DEBUG_VEC(a)
    res.emplace_back(a);
    const int index = this->maxMobileIndex(a, direction);
    DEBUG_VAR(index)
    if (index < 0) break; 
    const size_t value = a[index];
    if (direction[index]) {
      std::swap(a[index - 1], a[index]);
      std::swap(direction[index - 1], direction[index]);/// WARNING: swap direction as well
    } else {
      std::swap(a[index], a[index + 1]);
      std::swap(direction[index], direction[index + 1]);
    }/// else
    this->flipGreater(a, value, &direction);
  } while (true);
  DEBUG_END(JohnsonTrotter::run)
  return res;
}/// JohnsonTrotter::run

void JohnsonTrotter::flipGreater(const VI& a, const size_t value, VI* direction) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] > value) {
      (*direction)[i] = 1 - (*direction)[i];
    }
  }
}/// JohnsonTrotter::flipGreater

int JohnsonTrotter::maxMobileIndex(const VI& a, const VI& direction) {
  /// WARNING: comparison between int and size_t
  int max_a = -1;
  int max_i = -1;
  for (size_t i = 0; i < a.size(); ++i) {
    bool mobile_i = this->mobile(a, direction, i);
    DEBUG << i << ": ";
    DEBUG_VAR(mobile_i)
    if (static_cast<int>(a[i]) > max_a && mobile_i) {
      max_a = a[i];
      max_i = i;
    }/// if
  }/// for
  return max_i;
}/// JohnsonTrotter::maxMobileIndex

bool JohnsonTrotter::mobile(const VI& a, const VI& direction, const size_t i) {
  bool res = true;
  res = res && !((0 == i) && direction[i]);
  res = res && !((i > 0) && direction[i] && (a[i - 1] >= a[i]));
  res = res && !((a.size() - 1 == i) && !direction[i]);
  res = res && !((i < a.size() - 1) && !direction[i] && (a[i] <= a[i + 1]));
  return res;
}/// JohnsonTrotter::mobile

}/// namespace PlanarGraphColoring
