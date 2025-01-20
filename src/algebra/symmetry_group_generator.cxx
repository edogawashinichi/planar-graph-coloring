/// symmetry_group_generator.cxx

#include "symmetry_group_generator.h"
#include "../combinatorics/combinator/gray_code_combinator.h"
#include "../combinatorics/permutator/next_iter_permutator.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

void SymmetryGroupGenerator::run(const Group<Permutation>& group, const VI& generators, Group<Permutation>* subgroup) {
  DEBUG_START(SymmetryGroupGenerator::run group generators subgroup)
  auto symmetry_group = dynamic_cast<const SymmetryGroup&>(group);
  auto symmetry_subgroup = dynamic_cast<SymmetryGroup*>(subgroup);
  const size_t n = symmetry_group.size();
  VI added(n, 0);
  for (size_t k = 1; k <= generators.size(); ++k) {
    this->run(symmetry_group, generators, k, symmetry_subgroup, &added);
  }/// for
  DEBUG_END(SymmetryGroupGenerator::run group generators subgroup)
}/// SymmetryGroupGenerator::run

void SymmetryGroupGenerator::run(const SymmetryGroup& symmetry_group, const VI& generators, const size_t combination_size, SymmetryGroup* symmetry_subgroup, VI* added) {
  DEBUG_START(SymmetryGroupGenerator::run group generators combination_size subgroup added)
  DEBUG_VAR(combination_size)
  NextIterPermutator permutator;
  const VVI& permutator_vvi = permutator.run(combination_size);
  GrayCodeCombinator combinator;
  const VVI& index_choices = combinator.run(generators.size(), combination_size);
  for (const auto& index_choice : index_choices) {
    DEBUG_VEC(index_choice)
    VI choice_generators;
    map<size_t>(index_choice, generators, &choice_generators);
    DEBUG_VEC(choice_generators)
    /// WARNING: usually 2 permutations are not abelian, so combination shall be permuted
    for (const auto& permutator_vi : permutator_vvi) {
      VI permuted_choice_generators;
      map<size_t>(permutator_vi, choice_generators, &permuted_choice_generators);
      DEBUG_VEC(permuted_choice_generators)
      const size_t product = symmetry_group.product(permuted_choice_generators);
      DEBUG_VAR(product)
      this->run(symmetry_group, product, symmetry_subgroup, added);
    }/// for permutator_vvi
  }/// for choices
  DEBUG_END(SymmetryGroupGenerator::run group generators combination_size subgroup added)
}/// SymmetryGroupGenerator::run

void SymmetryGroupGenerator::run(const SymmetryGroup& symmetry_group, const size_t generator, SymmetryGroup* symmetry_subgroup, VI* added) {
  DEBUG_START(SymmetryGroupGenerator::run group generator subgroup added)
  DEBUG_VAR(generator)
  const VI& orbit = symmetry_group.orbit(generator);
  for (const auto& e : orbit) {
    /// WARNING: for 2 orbits of 2 permutations, they may be orthogonal, or coincide, or be a suborbit one another
    if (1 == (*added)[e]) continue;
    symmetry_subgroup->append(symmetry_group.constElement(e));
    (*added)[e] = 1;
  }/// for orbit
  DEBUG_END(SymmetryGroupGenerator::run group generator subgroup added)
}/// SymmetryGroupGenerator::run

}/// namespace PlanarGraphColoring
