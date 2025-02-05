/// relation_manager.cxx

#include "relation_manager.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

RelationManager::RelationManager() {
  color_result_ = std::make_unique<ColorResult>();
  relation_result_ = std::make_unique<RelationResult>();
  mapper_ = std::make_unique<Mapper>();
  digraph_result_ = std::make_unique<DigraphResult>();
}/// RelationManager::RelationManager

const ColorResult* RelationManager::getColorResultConst() const {
  return color_result_.get();
}/// RelationManager::getColorResultConst

ColorResult* RelationManager::getColorResult() {
  return color_result_.get();
}/// RelationManager::getColorResult

const RelationResult* RelationManager::getRelationResultConst() const {
  return relation_result_.get();
}/// RelationManager::getRelationResultConst

RelationResult* RelationManager::getRelationResult() {
  return relation_result_.get();
}/// RelationManager::getRelationResult

const Mapper* RelationManager::getMapperConst() const {
  return mapper_.get();
}/// RelationManager::getMapperConst

Mapper* RelationManager::getMapper() {
  return mapper_.get();
}/// RelationManager::getMapper

DigraphResult* RelationManager::getDigraphResult() {
  return digraph_result_.get();
}/// RelationManager::getDigraphResult

const DigraphResult* RelationManager::getDigraphResultConst() const {
  return digraph_result_.get();
}/// RelationManager::getDigraphResultConst

void RelationManager::show(std::ostream& cout) const {
  TEST_INFO
  cout << "color result:\n";
  showColorResult();
  cout << "relation result:\n";
  showRelationResult();
  cout << "mapper:\n";
  showMapper();
  cout << "digraph result:\n";
  showDigraphResult();
}/// RelationManager::show

void RelationManager::showColorResult() const {
  color_result_->show(std::cout, 20);
}/// RelationManager::showColorResult

void RelationManager::showRelationResult() const {
  relation_result_->show(std::cout, 20);
}/// RelationManager::showRelationResult

void RelationManager::showMapper() const {
  mapper_->show(std::cout, 20);
}/// RelationManager::showMapper

void RelationManager::showDigraphResult() const {
  digraph_result_->show(std::cout);
}/// RelationManagerowDigraphResult

}/// namespace PlanarGraphColoring
