/// birkhoff_diamond_analyst.cxx

#include "birkhoff_diamond_analyst.h"
#include "classification_interpreter.h"
#include "../operator/digraph_searcher.h"
#include "../basic/notation.h"

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
  INFO << "interpreter size: " << interpreter->size() << "\n"; \
  size_t cnt = 15; \
  for (size_t i = 0; i < interpreter->size(); ++i) { \
    /*INFO << i << "th size: " << interpreter->size(i) << "\n";*/ \
    if (interpreter->size(i) > 1) { \
      interpreter->show(i); \
      if (--cnt == 0) { \
        break; \
      } \
    } \
  } \
  INFO_END(BirkhoffDiamondAnalyst::reasonBySome) \
}/// BirkhoffDiamondAnalyst::reasonBySome

namespace PlanarGraphColoring {

FUNC(reasonByVertex, getVertexConst)
FUNC(reasonByColor, getColorConst)
FUNC(reasonByVertexColor, getVertexColorConst)
FUNC(reasonByKempe, getKempeConst)
FUNC(reasonByVertexColorKempe, getVertexColorKempeConst)

}/// namespace PlanarGraphColoring
