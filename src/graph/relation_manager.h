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
protected:
  std::unique_ptr<Mapper> mapper_;
  std::unique_ptr<Relation> relation_;
};/// class RelationManager

}/// namespace PlanarGraphColoring
