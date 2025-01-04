/// classification_interpreter.h

#pragma once

#include "interpreter.h"
#include "../color/color_result.h"
#include "../relation/relation_manager.h"
#include "../operator/digraph_searcher_result.h"
#include <unordered_set>

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
  void showWithRepresentative(const size_t i, const size_t n) const;
  std::vector<size_t> representative(const std::vector<size_t>& color) const;
  size_t getClass(const std::vector<size_t>& color) const;
  const ColorResult& getConst(const size_t index) const;
  inline const VI get(const size_t i, const size_t j) const {
    /// assuming: i,j valid
    return this->getConst(i).getInfo(j);
  }
  inline std::unordered_set<const ColorRepresentation*>& getValidTable() {
    return valid_table_;
  }
  const VI classValidTable() const;
protected:
  std::vector<ColorResult> color_class_;
  std::unordered_set<const ColorRepresentation*> valid_table_;
};/// class ClassificationInterpreter

}/// namespace PlanarGraphColoring
