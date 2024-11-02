/// birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../topology/birkhoff_diamond.h"
#include "../color/birkhoff_diamond_color_judger.h"
#include "../color/color_transformer.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void BirkhoffDiamondRelationBuilder::run(const Graph& birkhoff_diamond, const ColorResult& color_result, RelationManager* relation_manager) {
  PGC__SHOW_ENDL("start BirkhoffDiamondRelationBuilder")
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  relation_manager->setMapper(color_result);  
  relation_manager->showMapper();
  BirkhoffDiamondColorJudger bdcj;
  ColorTransformer ct;
  const size_t size = color_result.size();
  const size_t n = color_result.n();
  const size_t k = derived.boundarySize();
  PGC__SHOW_2VAR(size, n)
  size_t cnt_vertex = 0;
  size_t cnt_color = 0;
  for (size_t i = 0; i < color_result.size(); ++i) {
    PGC__SHOW_VAR(i)
    for (size_t j = i + 1; j < color_result.size(); ++j) {
      //PGC__SHOW_2VAR(i, j)
      int type = -1;
      std::vector<size_t> mapper(k);
      std::vector<size_t> imapper(k);
      if (bdcj.isIsomorphismByVertexSymmetry(color_result.getInfo(i, k), color_result.getInfo(j, k), &mapper)) {
        ++cnt_vertex;
        PGC__SHOW_3VAR(i, j, cnt_vertex)
        type = 1;
        ct.inverseVertexSymmetry(mapper, &imapper);
        relation_manager->addRelation(i, j, type, mapper, imapper);
      } else if (bdcj.isIsomorphismByColorSymmetry(color_result.getInfo(i, k), color_result.getInfo(j, k), &mapper)) {
        ++cnt_color;
        PGC__SHOW_3VAR(i, j, cnt_color)
        type = 0;
        ct.inverseColorSymmetry(mapper, &imapper);
        relation_manager->addRelation(i, j, type, mapper, imapper);
      }
    }
  }
  PGC__SHOW_2VAR(cnt_vertex, cnt_color)
  PGC__SHOW_ENDL("end BirkhoffDiamondRelationBuilder")
}/// BirkhoffDiamondRelationBuilder::run

}/// namespace PlanarGraphColoring
