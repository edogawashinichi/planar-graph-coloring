/// relation_manager.h

#pragma once

#include "relation_result.h"
#include "mapper.h"
#include "../color/color_result.h"
#include <memory>

namespace PlanarGraphColoring {

class RelationManager {
public:
  RelationManager();
  void show() const;
  void showColorResult() const;
  void showRelationResult() const;
  void showMapper() const;
  ColorResult* getColorResult();
  RelationResult* getRelationResult();
  Mapper* getMapper();
protected:
  std::unique_ptr<ColorResult> color_result_;
  std::unique_ptr<RelationResult> relation_result_;
  std::unique_ptr<Mapper> mapper_;
};/// class RelationManager

}/// namespace PlanarGraphColoring
