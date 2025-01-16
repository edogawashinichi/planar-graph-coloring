/// group_generator.h

#pragma once

#include "group.h"

namespace PlanarGraphColoring {

class GroupGenerator {
public:
  virtual void run(const Group& group, const VI& generators, Group* subgroup) = 0;
};/// class GroupGenerator

}/// namespace PlanarGraphColoring
