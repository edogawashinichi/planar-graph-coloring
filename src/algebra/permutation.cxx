/// permutation.cxx

#include "permutation.h"

namespace PlanarGraphColoring {

std::ostream& operator<<(std::ostream& cout, const Permutation& obj) {
  obj.show(cout);
  return cout;
}/// friend operator<<

Permutation operator*(const Permutation& lhs, const Permutation& rhs) {
  /// assuming: lhs.size() == rhs.size()
  /// left association: i-->lhs-->rhs-->j
  Permutation product;
  for (size_t i = 0; i < lhs.size(); ++i) {
    const size_t j = rhs.getConst(lhs.getConst(i));
    product.append(j);
  }/// for
  return product;
}/// friend operator*

bool operator==(const Permutation& lhs, const Permutation& rhs) {
  return lhs.getConst() == rhs.getConst();
}/// friend operator==

bool operator!=(const Permutation& lhs, const Permutation& rhs) {
  return lhs.getConst() != rhs.getConst();
}/// friend operator!=

void Permutation::show(std::ostream& cout) const {
  TEST_INFO
  //DimensionOneVector<size_t>::show();
  if (this->id()) {
    cout << "()";
  } else {
    const VVI& cycles = this->getCycles();
    for (const auto& cycle : cycles) {
      if (cycle.size() == 1) continue;
      cout << "(";
      for (const auto& i : cycle) {
        cout << i << " ";
      }/// for i
      cout << ")";
    }/// for cycle
  }/// else
  cout << "\n";
}/// Permutation::show

VVI Permutation::getCycles() const {
  VVI res;
  VI visited(this->size(), 0);
  for (size_t i = 0; i < this->size(); ++i) {
    if (1 == visited[i]) continue;
    VI cycle;
    size_t j = i;
    do {
      visited[j] = 1;
      cycle.emplace_back(j);
      j = this->getConst(j);
    } while (0 == visited[j]);
    res.emplace_back(cycle);
  }/// for
  return res;
}/// Permutation::getCycles

bool Permutation::id() const {
  bool res = true;
  for (size_t i = 0; i < this->size(); ++i) {
    if (i != this->getConst(i)) {
      res = false;
      break;
    }
  }/// for
  return res;
}/// Permutation::id

size_t Permutation::order() const {
  size_t res = 1;
  Permutation product(*this);
  while (!product.id()) {
    product = product * (*this);
    ++res;
  }/// while
  return res;
}/// Permutation::order

Permutation::Permutation(const VI& a) {
  this->get() = a;
}/// Permutation::Permutation

}/// namespace PlanarGraphColoring
