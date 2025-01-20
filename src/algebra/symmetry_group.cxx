/// symmetry_group.cxx

#include "symmetry_group.h"
#include "../combinatorics/permutator/next_iter_permutator.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

SymmetryGroup::SymmetryGroup(const size_t N) {
  const size_t n = fact(N);
  Group<Permutation>::elements().resize(n);
  NextIterPermutator ni;
  const VVI& res = ni.run(N);
  for (size_t i = 0; i < n; ++i) {
    Group<Permutation>::element(i) = std::move(Permutation(res[i]));
  }
}/// constructor

size_t SymmetryGroup::product(const VI& element_indices) const {
  /// TODO: move this function to Group<T>
  Permutation p(this->unit());
    for (const auto& index : element_indices) {
      const auto& element = Group<Permutation>::constElement(index);
      p = p * element;
    }/// for
    return this->getIndex(p.getConst());
}/// SymmetryGroup::product

std::vector<Permutation> SymmetryGroup::orbit(const Permutation& element) const {
  std::vector<Permutation> res;
  res.emplace_back(Permutation(this->unit()));/// WARNING: unit must be included
  Permutation product(element);
  while (!product.id()) {
    res.emplace_back(product);
    product = product * element;
  }
  return res;
}/// SymmetryGroup::orbit

VI SymmetryGroup::orbit(const size_t element_index) const {
  const auto& permutations = this->orbit(Group<Permutation>::constElement(element_index));
  VI res;
  for (const auto& permutation : permutations) {
    res.emplace_back(this->getIndex(permutation.getConst()));
  }
  return res;
}/// SymmetryGroup::orbit

size_t SymmetryGroup::getIndex(const VI& element) const {
  /// TODO: move to DimensionOneVector<T>
  size_t res = 0;
  for (size_t i = 0; i < Group<Permutation>::size(); ++i) {
    if (element == Group<Permutation>::constElement(i).getConst()) {
      res = i;
      break;
    }
  }/// for
  return res;
}/// SymmetryGroup::getIndex

VI SymmetryGroup::getIndices(const VVI& elements) const {
  VI res;
  for (const auto& element : elements) {
    res.emplace_back(this->getIndex(element));
  }/// for
  return res;
}/// SymmetryGroup::getIndices

void SymmetryGroup::show() const {
  TEST_INFO
  for (size_t i = 0; i < Group<Permutation>::size(); ++i) {
    std::cout << i << "th ";
    INFO_OBJ(Group<Permutation>::constElement(i))
  }/// for
}/// SymmetryGroup::show

const Permutation& SymmetryGroup::unit() const {
  for (const auto& permutation : Group<Permutation>::constElements()) {
    if (permutation.id()) return permutation;
  }/// for
  return Group<Permutation>::constElement(0);
}/// SymmetryGroup::unit

const Permutation& SymmetryGroup::inverse(const Permutation& e) const {
  for (const auto& f : Group<Permutation>::constElements()) {
    if (this->multiply(f, e) == this->unit()) return f;
  }/// for
  return Group<Permutation>::constElement(0);
}/// SymmetryGroup::inverse

const Permutation& SymmetryGroup::multiply(const Permutation& e, const Permutation& f) const {
  const Permutation& g = e * f;
  for (const auto& permutation : Group<Permutation>::constElements()) {
    if (permutation == g) return permutation;
  }
  return Group<Permutation>::constElement(0);
}/// SymmetryGroup::multiply

}/// namespace PlanarGraphColoring
