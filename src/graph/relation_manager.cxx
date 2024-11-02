/// relation_manager.cxx

#include "relation_manager.h"

namespace PlanarGraphColoring {

RelationManager::RelationManager() {
  mapper_ = std::make_unique<Mapper>();
  relation_ = std::make_unique<Relation>();
}/// RelationManager::RelationManager

void RelationManager::setMapper(const ColorResult& color_result) {
  for (size_t i = 0; i < color_result.size(); ++i) {
    ColorRepresentation* ptr = color_result.getConst(i);
    (mapper_->index2coloring_)[i] = ptr;
    (mapper_->coloring2index_)[ptr] = i;
  }
}/// RelationManager::setMapper

void RelationManager::showMapper() const {
  mapper_->show(20);
}/// RelationManager::showMapper

void RelationManager::addRelation(const size_t i, const size_t j, const int type, const std::vector<size_t>& mapper, const std::vector<size_t>& imapper) {
  relation_->add(i, j, type, mapper, imapper);
}/// RelationManager::addRelation

}/// namespace PlanarGraphColoring
