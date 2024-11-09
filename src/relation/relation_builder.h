/// relation_builder.h

#pragma once

#include "relation_manager.h"

namespace PlanarGraphColoring {

class RelationBuilder {
public:
  virtual void run(RelationManager* relation_manager) = 0;
  virtual void run(ColorResult* color_result) = 0;
  virtual void run(const ColorResult& color_result, RelationResult* relation_result, Mapper* mapper) = 0;
/*
  void analyzeIsomorphismByColorsAndVertices(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByVerticesAndColors(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByColors(ColorResults* color_results, RelationGraph* relation_graph);
  void analyzeIsomorphismByVertices(const BirkhoffDiamond& bd, ColorResults* color_results, RelationGraph* relation_graph);
*/
};/// class RelationBuilder

}/// namespace PlanarGraphColoring
