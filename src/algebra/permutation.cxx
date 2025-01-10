/// permutation.cxx

#include "permutation.h"

namespace PlanarGraphColoring {

void Permutation::show() const {
  TEST_INFO
  //INFO_VEC(f_)
  if (this->id()) {
    std::cout << "()";
  } else {
    const VVI& cycles = this->getCycles();
    for (const auto& cycle : cycles) {
      if (cycle.size() == 1) continue;
      std::cout << "(";
      for (const auto& i : cycle) {
        std::cout << i << " ";
      }/// for i
      std::cout << ")";
    }/// for cycle
  }/// else
  std::cout << "\n";
}/// Permutation::show

VVI Permutation::getCycles() const {
  VVI res;
  VI visited(f_.size(), 0);
  for (size_t i = 0; i < f_.size(); ++i) {
    if (1 == visited[i]) continue;
    VI cycle;
    size_t j = i;
    do {
      visited[j] = 1;
      cycle.emplace_back(j);
      j = f_[j];
    } while (0 == visited[j]);
    res.emplace_back(cycle);
  }/// for
  return res;
}/// Permutation::getCycles

bool Permutation::id() const {
  bool res = true;
  for (size_t i = 0; i < f_.size(); ++i) {
    if (i != f_[i]) {
      res = false;
      break;
    }
  }/// for
  return res;
}/// Permutation::id

Permutation::Permutation(const VI& a) {
  f_ = a;
}/// Permutation::Permutation

}/// namespace PlanarGraphColoring
