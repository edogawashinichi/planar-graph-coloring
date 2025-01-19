/// symmetry_group_generator.h

#pragma once

#include "group_generator.h"
#include "permutation.h"
#include "symmetry_group.h"

namespace PlanarGraphColoring {

class SymmetryGroupGenerator : public GroupGenerator<Permutation> {
public:
  virtual void run(const Group<Permutation>& symmetry_group, const VI& generators, Group<Permutation>* symmetry_subgroup) override;
protected:
  void run(const SymmetryGroup& symmetry_group, const VI& generators, const size_t combination_size, SymmetryGroup* symmetry_subgroup, VI* added);
  void run(const SymmetryGroup& symmetry_group, const size_t generator, SymmetryGroup* symmetry_subgroup, VI* added);
};/// class SymmetryGroupGenerator

}/// namespace PlanarGraphColoring
