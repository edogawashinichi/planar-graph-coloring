/// symmetry_group_generator.cxx

#include "symmetry_group_generator.h"
#include "permutation_transformer.h"
#include "../combinatorics/combinator/gray_code_combinator.h"
#include "../combinatorics/permutator/next_iter_permutator.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

void SymmetryGroupGenerator::run(const Group<Permutation>& group, const VVI& generators, Group<Permutation>* subgroup) {
  PermutationTransformer transformer;
  this->run(group, transformer.run(generators), subgroup);
}/// SymmetryGroupGenerator::run

void SymmetryGroupGenerator::run(const Group<Permutation>& group, const std::vector<Permutation>& generators, Group<Permutation>* subgroup) {
  DEBUG_START(SymmetryGroupGenerator::run group generators subgroup)
  auto symmetry_group = dynamic_cast<const SymmetryGroup&>(group);
  auto symmetry_subgroup = dynamic_cast<SymmetryGroup*>(subgroup);
  VI added(symmetry_group.size(), 0);
  for (size_t k = 1; k <= generators.size(); ++k) {
    this->run(symmetry_group, generators, k, symmetry_subgroup, &added);
  }/// for
  DEBUG_END(SymmetryGroupGenerator::run group generators subgroup)
}/// SymmetryGroupGenerator::run

void SymmetryGroupGenerator::run(const SymmetryGroup& symmetry_group, const std::vector<Permutation>& generators, const size_t combination_size, SymmetryGroup* symmetry_subgroup, VI* added) {
  DEBUG_START(SymmetryGroupGenerator::run group generators combination_size subgroup added)
  DEBUG_VAR(combination_size)
  const VI& index_generators = symmetry_group.index(generators);
  GrayCodeCombinator combinator;
  const VVI& combinations = combinator.run(generators.size(), combination_size);
  NextIterPermutator permutator;
  const VVI& permutations = permutator.run(combination_size);
  for (const VI& combination : combinations) {
    DEBUG_VEC(combination)
    VI combine_index_generators;
    map<size_t>(combination, index_generators, &combine_index_generators);
    DEBUG_VEC(combine_index_generators)
    /// WARNING: usually 2 permutations are not abelian, so combination shall be permuted
    for (const VI& permutation : permutations) {
      VI permute_combine_index_generators;
      map<size_t>(permutation, combine_index_generators, &permute_combine_index_generators);
      DEBUG_VEC(permute_combine_index_generators)
      const Permutation& product = symmetry_group.product(permute_combine_index_generators);
      DEBUG_OBJ(product)
      this->run(symmetry_group, product, symmetry_subgroup, added);
    }/// for permutations
  }/// for combinations
  DEBUG_END(SymmetryGroupGenerator::run group generators combination_size subgroup added)
}/// SymmetryGroupGenerator::run

void SymmetryGroupGenerator::run(const SymmetryGroup& symmetry_group, const Permutation& generator, SymmetryGroup* symmetry_subgroup, VI* added) {
  DEBUG_START(SymmetryGroupGenerator::run group generator subgroup added)
  DEBUG_VAR(generator)
  const VI& orbit = symmetry_group.orbit(generator);
  for (const size_t index : orbit) {
    /// WARNING: for 2 orbits of 2 permutations, they may be orthogonal, or coincide, or be a suborbit one another
    if (1 == (*added)[index]) continue;
    symmetry_subgroup->append(symmetry_group.constElement(index));
    (*added)[index] = 1;
  }/// for orbit
  DEBUG_END(SymmetryGroupGenerator::run group generator subgroup added)
}/// SymmetryGroupGenerator::run

}/// namespace PlanarGraphColoring
