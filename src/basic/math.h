/// math.h

#pragma once

#include "notation.h"
#include <vector>
#include <functional>
#include <algorithm>

namespace PlanarGraphColoring {

/// template function assertion and definition must be put together

/* x --f--> y */
template<typename T>
void map(const std::vector<T>& X, const std::vector<T>& f, std::vector<T>* Y) {
  /// assuming: X in domain of f
  /// assuming: X and Y have the same domain
  /// T : size_t / int / long (discrete types only)
  std::transform(X.begin(), X.end(), Y->begin(), [&](const size_t x){return f[x];});
}/// map

/* C = A - B */
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

/* {0, 1, ..., n-1} */
template<typename T>
std::vector<T> id(const size_t n) {
  std::vector<T> res(n, 0);
  int a = 0;
  std::generate(res.begin(), res.end(), [&]{return a++;});
  return res;
}/// id

template<typename T>
void dict_sort(std::vector<std::pair<T, T>>& vtt, const bool ascend = true) {
  auto cmp = [&](const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) -> bool {
    if (lhs.first != rhs.first) return (lhs.first < rhs.first) == ascend;
    return (lhs.second < rhs.second) == ascend;
  };
  std::sort(vtt.begin(), vtt.end(), cmp);
}/// dict_sort

template<typename T>
void dict_sort(std::vector<std::vector<T>>& vv, const bool ascend = true) {
  auto cmp = [&](const std::vector<T>& lhs, const std::vector<T>& rhs) -> bool {
    const size_t n = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
    for (size_t i = 0; i < n; ++i) {
      if (lhs[i] == rhs[i]) continue;
      return (lhs[i] < rhs[i]) == ascend;
    }
    return (lhs.size() <= rhs.size()) == ascend;
  };
  std::sort(vv.begin(), vv.end(), cmp);
}/// dict_sort

template<typename T>
T max(const T& a, const T& b, const T& c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

}/// namespace PlanarGraphColoring
