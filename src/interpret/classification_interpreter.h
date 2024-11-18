/// classification_interpreter.h

#pragma once

#include "interpreter.h"
#include "../color/color_result.h"
#include "../relation/relation_manager.h"
#include "../operator/digraph_searcher_result.h"

namespace PlanarGraphColoring {

class ClassificationInterpreter : public Interpreter {
public:
  ClassificationInterpreter();
  void set(const RelationManager& relation_manager, DigraphSearcherResult& digraph_searcher_result);
  void append(const ColorResult& table, const size_t index);
  void extend(const ColorResult& table, const size_t index);
  inline size_t size() const {
    return color_class_.size();
  }
  inline size_t size(const size_t index) const {
    return color_class_[index].size();
  }
  void show() const;
  void show(const size_t index) const;
  std::vector<size_t> representative(const std::vector<size_t>& color) const;
protected:
  std::vector<ColorResult> color_class_;
};/// class ClassificationInterpreter

}/// namespace PlanarGraphColoring
