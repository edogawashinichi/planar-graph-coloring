/// gray_code_combinator.cxx

#include "gray_code_combinator.h"
#include "../../basic/global.h"

/// TODO: solve non-constant-expression bug of COMBINATION_MAX_N

namespace PlanarGraphColoring {

VVI GrayCodeCombinator::run(const size_t n, const size_t k) {
  /// TIME COMPLEXITY: O(n * (n, k))
  /// WARNING: supporting max number 34 at present
  VVI res;
  const LL M = static_cast<LL>(1) << static_cast<LL>(n);
  for (LL i = 0; i < M ; ++i) {
    std::bitset<COMBINATION_MAX_N> a;/// bitset size must be const
    this->getGrayCode(i, &a);
    if (a.count() == k) {
      VI v;
      for (size_t j = 0; j < n; ++j) {
        if (!a.test(j)) continue;
        v.emplace_back(j);
      }/// for j
      res.emplace_back(v);
    }/// if
  }/// for i
  return res;
}/// GrayCodeCombinator::run

void GrayCodeCombinator::getGrayCode(const LL& i, std::bitset<COMBINATION_MAX_N>* a) {
  //*a = i ^ (i >> static_cast<LL>(1));
  *a = std::bitset<COMBINATION_MAX_N>(i) ^ (std::bitset<COMBINATION_MAX_N>(i) >> 1);
}/// GrayCodeCombinator::getGrayCode

}/// namespace PlanarGraphColoring
