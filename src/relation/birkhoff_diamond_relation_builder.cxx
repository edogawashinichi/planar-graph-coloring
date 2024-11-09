/// birkhoff_diamond_relation_builder.cxx

#include "birkhoff_diamond_relation_builder.h"
#include "../color/birkhoff_diamond_colorer.h"
#include "../topology/birkhoff_diamond.h"
#include "../color/birkhoff_diamond_color_judger.h"
#include "../color/color_transformer.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void BirkhoffDiamondRelationBuilder::run(RelationManager* relation_manager) {
  INFO_START(BirkhoffDiamondRelationBuilder::run RelationManger)
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    PGC__SHOW_ENDL("start BirkhoffDiamondRelationBuilder::run RelationManager")
  }
  run(relation_manager->getColorResult());
  run(*(relation_manager->getColorResult()), relation_manager->getRelationResult(), relation_manager->getMapper(), relation_manager->getDigraphResult());
  INFO_END(BirkhoffDiamondRelationBuilder::run RelationManager)
}/// BirkhoffDiamondRelationBuilder::run

void BirkhoffDiamondRelationBuilder::run(ColorResult* color_result) {
  INFO_START(BirkhoffDiamondRelationBuilder::run ColorResult)
  const BirkhoffDiamond birkhoff_diamond;
  BirkhoffDiamondColorer colorer;
  colorer.run(birkhoff_diamond, color_result);
  const size_t color_result_size = color_result->size();
  INFO_VAR(color_result_size)
  INFO_END(BirkhoffDiamondRelationBuilder::run ColorResult)
}/// BirkhoffDiamondRelationBuilder::run

void BirkhoffDiamondRelationBuilder::run(const ColorResult& color_result, RelationResult* relation_result, Mapper* mapper, DigraphResult* digraph_result) {
  INFO_START(BirkhoffDiamondRelationBuilder::run RelationResult Mapper DigraphResult)
  digraph_result->setSize(color_result.size());
  const BirkhoffDiamond birkhoff_diamond;
  BirkhoffDiamondColorJudger judger;
  ColorTransformer transformer;
  const size_t k = birkhoff_diamond.boundarySize();
  size_t cnt_vertex = 0;
  size_t cnt_color = 0;
  for (size_t i = 0; i < color_result.size(); ++i) {
    if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
      PGC__SHOW_VAR(i)
    }
    for (size_t j = i + 1; j < color_result.size(); ++j) {
      size_t type = 0;
      std::vector<size_t> transform(k);
      std::vector<size_t> itransform(k);
      if (judger.isIsomorphismByVertexSymmetry(color_result.getInfo(i, k), color_result.getInfo(j, k), &transform)) {
        ++cnt_vertex;
        if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
          PGC__SHOW_3VAR(i, j, cnt_vertex)
        }
        type = 1;
        transformer.inverseVertexSymmetry(transform, &itransform);
        mapper->insert(relation_result->size(), i, j);
        relation_result->append(Relation(i, j, type, transform));
        mapper->insert(relation_result->size(), j, i);
        relation_result->append(Relation(j, i, type, itransform));
        digraph_result->getVertex()->append(i, j);
        digraph_result->getVertexColor()->append(i, j);
        digraph_result->getVertexColorKempe()->append(i, j);
      } else if (judger.isIsomorphismByColorSymmetry(color_result.getInfo(i, k), color_result.getInfo(j, k), &transform)) {
        ++cnt_color;
        if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
          PGC__SHOW_3VAR(i, j, cnt_color)
        }
        type = 0;
        transformer.inverseColorSymmetry(transform, &itransform);
        mapper->insert(relation_result->size(), i, j);
        relation_result->append(Relation(i, j, type, transform));
        mapper->insert(relation_result->size(), j, i);
        relation_result->append(Relation(j, i, type, itransform));
        digraph_result->getColor()->append(i, j);
        digraph_result->getVertexColor()->append(i, j);
        digraph_result->getVertexColorKempe()->append(i, j);
      }/// else if
    }/// for j
  }/// for i
  INFO_2VAR(cnt_vertex, cnt_color)
  const size_t relation_result_size = relation_result->size();
  const size_t mapper_size = mapper->size();
  INFO_VAR(relation_result_size)
  INFO_VAR(mapper_size)
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    digraph_result->show();
  }
  INFO_END(BirkhoffDiamondRelationBuilder::run RelationResult Mapper Digraph)
}/// BirkhoffDiamondRelationBuilder::run

}/// namespace PlanarGraphColoring
