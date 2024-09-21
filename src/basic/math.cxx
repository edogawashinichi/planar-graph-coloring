/// math.cxx

#include "math.h"
#include <functional>

namespace PlanarGraphColoring {

void map(const std::vector<int>& X, const std::vector<int>& f, std::vector<int>* Y) {
  /// assuming: X in domain of f
  /// assuming: X and Y have the same domain
  std::transform(X.begin(), X.end(), Y->begin(), [&](const int x){return f[x];});
}/// map

void diff(const std::vector<int>& A, const std::vector<int>& B, std::vector<int>* C) {
  for (const auto a : A) {
    bool contain = false;
    for (const auto b : B) {
      if (a == b) {
        contain = true;
        break;
      }
    }/// for B
    if (contain) continue;
    C->emplace_back(a);
  }/// for A
}/// diff

std::vector<int> id(const size_t n) {
  std::vector<int> res(n, 0);
  int a = 0;
  std::generate(res.begin(), res.end(), [&]{return a++;});
  return res;
}/// id

}/// namespace PlanarGraphColoring
