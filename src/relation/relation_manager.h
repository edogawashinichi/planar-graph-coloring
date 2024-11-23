/// relation_manager.h

#pragma once

#include "relation_result.h"
#include "mapper.h"
#include "../color/color_result.h"
#include "digraph_result.h"
#include <memory>

namespace PlanarGraphColoring {

class RelationManager {
public:
  RelationManager();
  void show() const;
  void showColorResult() const;
  void showRelationResult() const;
  void showMapper() const;
  void showDigraphResult() const;
  const ColorResult* getColorResultConst() const;
  ColorResult* getColorResult();
  RelationResult* getRelationResult();
  const RelationResult* getRelationResultConst() const;
  Mapper* getMapper();
  const Mapper* getMapperConst() const;
  DigraphResult* getDigraphResult();
  const DigraphResult* getDigraphResultConst() const;
protected:
  std::unique_ptr<ColorResult> color_result_;
  std::unique_ptr<RelationResult> relation_result_;
  std::unique_ptr<Mapper> mapper_;
  std::unique_ptr<DigraphResult> digraph_result_;
};/// class RelationManager

}/// namespace PlanarGraphColoring
