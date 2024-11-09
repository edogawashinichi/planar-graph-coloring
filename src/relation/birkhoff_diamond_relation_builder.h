/// birkhoff_diamond_relation_builder.h

#pragma once

#include "relation_builder.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondRelationBuilder : public RelationBuilder {
public:
  virtual void run(RelationManager* relation_manager) override;
  virtual void run(ColorResult* color_result) override;
  virtual void run(const ColorResult& color_result, RelationResult* relation_result, Mapper* mapper) override;
};/// class BirkhoffDiamondRelationBuilder

}/// namespace PlanarGraphColoring
