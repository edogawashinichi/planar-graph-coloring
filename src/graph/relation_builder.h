/// relation_builder.h

#pragma once

#include "../basic/graph.h"
#include "../color/color_result.h"
#include "relation_manager.h"

namespace PlanarGraphColoring {

class RelationBuilder {
public:
  virtual void run(const Graph& graph, const ColorResult& color_result, RelationManager* relation_manager) = 0;
/*
  void analyzeIsomorphismByColorsAndVertices(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByVerticesAndColors(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByColors(ColorResults* color_results, RelationGraph* relation_graph);
  void analyzeIsomorphismByVertices(const BirkhoffDiamond& bd, ColorResults* color_results, RelationGraph* relation_graph);
*/
};/// class RelationBuilder

}/// namespace PlanarGraphColoring
