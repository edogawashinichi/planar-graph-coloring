/// birkhoff_diamond_relation_builder.h

#pragma once

#include "relation_builder.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondRelationBuilder : public RelationBuilder {
public:
  virtual void run(const Graph& birkhoff_diamond, const ColorResult& color_result, RelationManager* relation_manager) override;
};/// class BirkhoffDiamondRelationBuilder

}/// namespace PlanarGraphColoring
