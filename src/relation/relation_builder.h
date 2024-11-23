/// relation_builder.h

#pragma once

#include "relation_manager.h"

namespace PlanarGraphColoring {

class RelationBuilder {
public:
  virtual void run(RelationManager* relation_manager) = 0;
  virtual void run(ColorResult* color_result) = 0;
  virtual void run(const ColorResult& color_result, RelationResult* relation_result, Mapper* mapper, DigraphResult* digraph_result) = 0;
};/// class RelationBuilder

}/// namespace PlanarGraphColoring
