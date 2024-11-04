/// relation_manager.h

#pragma once

#include "relation.h"
#include "../color/color_result.h"
#include <memory>

namespace PlanarGraphColoring {

class RelationManager {
public:
  RelationManager();
  void setMapper(const ColorResult& color_result);
  void showMapper() const;
  void addRelation(const size_t i, const size_t j, const int type, const std::vector<size_t>& mapper, const std::vector<size_t>& imapper);
protected:
  std::unique_ptr<Mapper> mapper_;
  std::unique_ptr<Relation> relation_;
};/// class RelationManager

}/// namespace PlanarGraphColoring
