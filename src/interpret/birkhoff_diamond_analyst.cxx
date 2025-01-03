/// birkhoff_diamond_analyst.cxx

#include "birkhoff_diamond_analyst.h"
#include "classification_interpreter.h"
#include "routing_interpreter.h"
#include "kempe_interpreter.h"
#include "../operator/digraph_searcher.h"
#include "../basic/notation.h"
#include "../color/naive_color_representation.h"
#include "../color/kempe/birkhoff_diamond_kempe_chain_interchanger.h"

/// TODO: dfs result may differ, how to memorize classification interpreter

#define FUNC(reasonBySome, getSomeConst) \
void BirkhoffDiamondAnalyst::reasonBySome(const RelationManager& relation_manager, Interpreter* classification_interpreter) { \
  INFO_START(BirkhoffDiamondAnalyst::reasonBySome) \
  auto interpreter = dynamic_cast<ClassificationInterpreter*>(classification_interpreter); \
  DigraphSearcher searcher; \
  DigraphSearcherResult result; \
  searcher.dfs(*(relation_manager.getDigraphResultConst()->getSomeConst()), &result); \
  const size_t weak_component_size = result.weakComponentSize(); \
  INFO_VAR(weak_component_size) \
  interpreter->set(relation_manager, result); \
  INFO << "classification interpreter size: " << interpreter->size() << "\n"; \
  const size_t cnt = 15; \
  for (size_t i = 0; i < interpreter->size() && i < cnt; ++i) { \
    DEBUG << i << "th size: " << interpreter->size(i) << "\n"; \
    interpreter->show(i); \
  } \
  INFO_END(BirkhoffDiamondAnalyst::reasonBySome) \
}/// BirkhoffDiamondAnalyst::reasonBySome

namespace PlanarGraphColoring {

FUNC(reasonByVertex, getVertexConst)
FUNC(reasonByColor, getColorConst)
FUNC(reasonByVertexColor, getVertexColorConst)
//FUNC(reasonByKempe, getKempeConst)
//FUNC(reasonByVertexColorKempe, getVertexColorKempeConst)

void BirkhoffDiamondAnalyst::reasonByVertexColor(const RelationManager& manager, const Interpreter& input, const size_t i, const size_t j, const size_t k, Interpreter* output) {
  /// assuming: input contains (i, j) and (i, k)
  INFO_START(BirkhoffDiamondAnalyst::reasonByVertexColor)
  auto classification_interpreter = dynamic_cast<const ClassificationInterpreter&>(input);
  auto routing_interpreter = dynamic_cast<RoutingInterpreter*>(output);
  const size_t coloring_ij_index = manager.getColorResultConst()->find(classification_interpreter.get(i, j));
  const size_t coloring_ik_index = manager.getColorResultConst()->find(classification_interpreter.get(i, k));
  INFO_2VAR(coloring_ij_index, coloring_ik_index)
  DEBUG_OBJ(*(classification_interpreter.getConst(i).getConst(j)))
  DEBUG_OBJ(*(classification_interpreter.getConst(i).getConst(k)))
  auto representative_ij = classification_interpreter.representative(classification_interpreter.get(i, j));
  auto representative_ik = classification_interpreter.representative(classification_interpreter.get(i, k));
  DEBUG_OBJ(NaiveColorRepresentation(representative_ij))
  DEBUG_OBJ(NaiveColorRepresentation(representative_ik))
  DigraphSearcher searcher;
  DigraphSearcherResult result;
  searcher.dijkstra(*(manager.getDigraphResultConst()->getVertexColorConst()), {coloring_ij_index, coloring_ik_index}, &result);
  routing_interpreter->set(manager, result, coloring_ij_index, coloring_ik_index);
  DEBUG_OBJ(*routing_interpreter)
  INFO_END(BirkhoffDiamondAnalyst::reasonByVertexColor)
}/// BirkhoffDiamondAnalyst::reasonByVertexColor

void BirkhoffDiamondAnalyst::reasonByVertexColor(const RelationManager& manager, const Interpreter& input, const size_t i, Interpreter* output) {
  INFO_START(BirkhoffDiamondAnalyst::reasonByVertexColor)
  auto classification_interpreter = dynamic_cast<const ClassificationInterpreter&>(input);
  auto kempe_interpreter = dynamic_cast<KempeInterpreter*>(output);
  INFO_VAR(i)
  const VI representative = classification_interpreter.get(i, 0);
  const size_t representative_index = manager.getColorResultConst()->find(representative);
  NaiveColorRepresentation representative_coloring(representative);
  INFO_VAR(representative_index)
  INFO_OBJ(representative_coloring)
  BirkhoffDiamondKempeChainInterchanger interchanger;
  BirkhoffDiamond diamond;
  interchanger.run(diamond, representative_coloring, *(manager.getColorResultConst()), &(kempe_interpreter->getKempeChainResult()));
  const auto& separating_interchange = kempe_interpreter->constKempeChainResult().separating_.interchange_;
  const auto& separated_interchange = kempe_interpreter->constKempeChainResult().separated_.interchange_;
  const size_t separating_class = classification_interpreter.getClass(separating_interchange.getVector());
  const size_t separated_class = classification_interpreter.getClass(separated_interchange.getVector());
  const size_t separating_class_index = classification_interpreter.getConst(separating_class).find(separating_interchange.getVector());
  const size_t separated_class_index = classification_interpreter.getConst(separated_class).find(separated_interchange.getVector());
  this->reasonByVertexColor(manager, classification_interpreter, separating_class, separating_class_index, 0, &(kempe_interpreter->getSeparatingRoute()));
  this->reasonByVertexColor(manager, classification_interpreter, separated_class, separated_class_index, 0, &(kempe_interpreter->getSeparatedRoute()));
  kempe_interpreter->setClass(i, separating_class, separated_class);
  kempe_interpreter->setColoring(representative_coloring);
  INFO_END(BirkhoffDiamondAnalyst::reasonByVertexColor)
}/// BirkhoffDiamondAnalyst::reasonByVertexColor

}/// namespace PlanarGraphColoring
