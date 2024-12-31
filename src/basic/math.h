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

/* return A cap B nonempty */
template<typename T>
bool cap(const std::vector<T>& A, const std::vector<T>& B) {
  /// TODO: optimize by hash table
  bool res = false;
  for (const auto& a : A) {
    for (const auto& b : B) {
      if (b != a) continue;
      res = true;
      break;
    }/// for b
    if (res) break;
  }/// for a
  return res;
}/// cap

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
void cycle_sort(std::vector<T>& v, const size_t cycle, const bool ascend = true) {
  /// assuming: v is continuous around the cycle
  if (v.empty()) return;
  if (ascend) {
    std::sort(v.begin(), v.end());
  } else {
    std::sort(v.begin(), v.end(), std::greater<T>());
  }/// else
  bool gap = false;
  size_t i = 0;
  for (; i < v.size() - 1; ++i) {
    if (1 == v[i] - v[i+1] || 1 == v[i+1] - v[i]) continue;
    gap = true;
    break;
  }/// for
  if (gap) {
    std::vector<T> temp;
    for (size_t j = i + 1; j < v.size(); ++j) {
      temp.emplace_back(v[j]);
    }/// for
    for (size_t j = 0; j <= i; ++j) {
      temp.emplace_back(v[j]);
    }/// for
    v.swap(temp);
  }/// if gap
}/// cycle_sort

template<typename T>
void cycle_sort(std::vector<std::vector<T>>& vv, const size_t cycle, const bool ascend = true) {
  /// assuming: each v in vv is continuous around the cycle
  ///           any distinct u,v in vv don't overlap
  for (auto& v : vv) {
    cycle_sort<T>(v, cycle, ascend);
  }
  auto cmp = [&](const std::vector<T>& lhs, const std::vector<T>& rhs) -> bool {
    if (lhs.empty() || rhs.empty()) {
      return lhs.empty() == ascend;
    }
    return ascend ? lhs.back() < rhs.back() : lhs.front() > rhs.front();
  };
  std::sort(vv.begin(), vv.end(), cmp);
}/// cycle_sort

template<typename T>
T max(const T& a, const T& b, const T& c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

}/// namespace PlanarGraphColoring
