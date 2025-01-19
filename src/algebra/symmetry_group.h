/// symmetry_group.h

/// symmetry group is a group whose elements are permutations

#pragma once

#include "group.h"
#include "permutation.h"
#include "permutator/next_iter_permutator.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

class SymmetryGroup : public Group<Permutation> {
public:
  inline SymmetryGroup() = default;
  inline SymmetryGroup(const size_t N) {
    const size_t n = fact(N);
    Group<Permutation>::elements().resize(n);
    NextIterPermutator ni;
    const VVI& res = ni.run(N);
    for (size_t i = 0; i < n; ++i) {
      Group<Permutation>::element(i) = std::move(Permutation(res[i]));
    }
  }/// constructor
  inline size_t product(const VI& element_indices) const {
    /// TODO: move this function to Group<T>
    Permutation p(this->unit());
    for (const auto& index : element_indices) {
      const auto& element = Group<Permutation>::constElement(index);
      p = p * element;
    }/// for
    return this->getIndex(p.getConst());
  }/// product
  inline virtual std::vector<Permutation> orbit(const Permutation& element) const override {
    std::vector<Permutation> res;
    res.emplace_back(Permutation(this->unit()));/// WARNING: unit must be included
    Permutation product(element);
    do {
      res.emplace_back(product);
      product = product * element;
    } while (!product.id());
    return res;
  }/// orbit
  inline virtual VI orbit(const size_t element_index) const override {
    const auto& permutations = this->orbit(Group<Permutation>::constElement(element_index));
    VI res;
    for (const auto& permutation : permutations) {
      res.emplace_back(this->getIndex(permutation.getConst()));
    }
    return res;
  }/// orbit
  inline size_t getIndex(const VI& element) const {
    /// TODO: move this function to DimensionOneVector<T>
    size_t res = 0;
    for (size_t i = 0; i < Group<Permutation>::size(); ++i) {
      if (element == Group<Permutation>::constElement(i).getConst()) {
        res = i;
        break;
      }
    }/// for
    return res;
  }/// getIndex
  inline VI getIndices(const VVI& elements) const {
    VI res;
    for (const auto& element : elements) {
      res.emplace_back(this->getIndex(element));
    }/// for
    return res;
  }/// getIndices
  inline virtual void show() const override {
    TEST_INFO
    for (size_t i = 0; i < Group<Permutation>::size(); ++i) {
      std::cout << i << "th ";
      INFO_OBJ(Group<Permutation>::constElement(i))
    }/// for
  }/// show
  inline virtual const Permutation& unit() const override {
    for (const auto& permutation : Group<Permutation>::constElements()) {
      if (permutation.id()) return permutation;
    }/// for
    return Group<Permutation>::constElement(0);
  }/// unit
  inline virtual const Permutation& inverse(const Permutation& e) const override {
    for (const auto& f : Group<Permutation>::constElements()) {
      if (this->multiply(f, e) == this->unit()) return f;
    }/// for
    return Group<Permutation>::constElement(0);
  }/// inverse
  inline virtual const Permutation& multiply(const Permutation& e, const Permutation& f) const override {
    const Permutation& g = e * f;
    for (const auto& permutation : Group<Permutation>::constElements()) {
      if (permutation == g) return permutation;
    }
    return Group<Permutation>::constElement(0);
  }/// multiply
};/// class SymmetryGroup

}/// namespace PlanarGraphColoring
