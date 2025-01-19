/// group_generator.h

/// template interface

#pragma once

#include "group.h"

namespace PlanarGraphColoring {

template<typename T>
class GroupGenerator {
public:
  virtual void run(const Group<T>& group, const VI& generators, Group<T>* subgroup) = 0;
};/// class GroupGenerator

}/// namespace PlanarGraphColoring
