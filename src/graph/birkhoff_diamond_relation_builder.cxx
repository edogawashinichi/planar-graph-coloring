/// birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

void BirkhoffDiamondRelationBuilder::run(const Graph& birkhoff_diamond, const ColorResult& color_result, RelationManager* relation_manager) {
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  derived;
  relation_manager->setMapper(color_result);  
  relation_manager->showMapper();
  
}/// BirkhoffDiamondRelationBuilder::run

}/// namespace PlanarGraphColoring
