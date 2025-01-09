/// math.cxx

#include "math.h"

namespace PlanarGraphColoring {

size_t fact(const size_t n) {
  /// assuming: n! is no more than max value of size_t
  size_t res = 1;
  for (size_t i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}/// fact

/*
template<typename T>
void map(const std::vector<T>& X, const std::vector<T>& f, std::vector<T>* Y) {
  /// assuming: X in domain of f
  /// assuming: X and Y have the same domain
  /// T : size_t / int / long (discrete types only)
  std::transform(X.begin(), X.end(), Y->begin(), [&](const size_t x){return f[x];});
}/// map

template<typename T>
void diff(const std::vector<T>& A, const std::vector<T>& B, std::vector<T>* C) {
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

template<typename T>
std::vector<T> id(const size_t n) {
  std::vector<T> res(n, 0);
  int a = 0;
  std::generate(res.begin(), res.end(), [&]{return a++;});
  return res;
}/// id
*/

}/// namespace PlanarGraphColoring
