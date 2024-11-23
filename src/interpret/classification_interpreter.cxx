/// classification_interpreter.cxx

#include "classification_interpreter.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

constexpr size_t N = 5;

ClassificationInterpreter::ClassificationInterpreter() {
  color_class_.clear();
}/// ClassificationInterpreter::ClassificationInterpreter

std::vector<size_t> ClassificationInterpreter::representative(const std::vector<size_t>& color) const {
  std::vector<size_t> res;
  for (const auto& color_result : color_class_) {
    for (size_t i = 0; i < color_result.size(); ++i) {
      if (color == color_result.getInfo(i)) {
        res = color_result.getInfo(0);
        break;
      }/// if
    }/// for
  }/// for
  return res;
}/// ClassificationInterpreter::representative

size_t ClassificationInterpreter::getClass(const std::vector<size_t>& color) const {
  size_t res = 0;
  for (size_t i = 0; i < color_class_.size(); ++i) {
    for (size_t j = 0; j < color_class_[i].size(); ++j) {
      if (color == color_class_[i].getInfo(j)) {
        res = i;
        break;
      }/// if
    }/// for
  }/// for
  return res;
}/// ClassificationInterpreter::getClass

void ClassificationInterpreter::set(const RelationManager& relation_manager, DigraphSearcherResult& digraph_searcher_result) {
  DEBUG_START(ClassificationInterpreter::set)
  const auto& color_result = *(relation_manager.getColorResultConst());
  const size_t weak_component_size = digraph_searcher_result.weakComponentSize();
  for (size_t i = 0; i < weak_component_size; ++i) {
    append(color_result, digraph_searcher_result.getWeakComponent(i, 0));
    for (size_t j = 1; j < digraph_searcher_result.weakComponentSize(i); ++j) {
      extend(color_result, digraph_searcher_result.getWeakComponent(i, j));
    }/// for j
  }/// for i
  DEBUG_END(ClassificationInterpreter::set)
}/// ClassificationInterpreter::set

void ClassificationInterpreter::append(const ColorResult& table, const size_t index) {
  DEBUG_START(ClassificationInterpreter::append)
  {
  ColorResult result;
  DEBUG << "before result.append\n";
  result.append(table.getInfo(index));
  DEBUG << "before color_class_.emplace_back\n";
  color_class_.emplace_back(std::move(result));
  //color_class_.push_back(result);
  //color_class_.emplace_back(result);/// memory leak risk
  }
  DEBUG_END(ClassificationInterpreter::append)
}/// ClassificationInterpreter::append

void ClassificationInterpreter::extend(const ColorResult& table, const size_t index) {
  color_class_.back().append(table.getInfo(index));
}/// ClassificationInterpreter::extend

void ClassificationInterpreter::show() const {
  TEST_INFO
  INFO_START(ClassificationInterpreter::show)
  for (size_t i = 0; i < color_class_.size(); ++i) {
    std::cout << i << "th class (total " << color_class_[i].size() << "):\n";
    this->showWithRepresentative(i, N);
  }
  INFO_END(ClassificationInterpreter::show)
}/// ClassificationInterpreter::show

void ClassificationInterpreter::showWithRepresentative(const size_t i, const size_t n) const {
  color_class_[i].showWith("representative", n);
}/// ClassificationInterpreter::showWithRepresentative

void ClassificationInterpreter::show(const size_t index) const {
  TEST_INFO
  /// assuming: 0 <= index < size
  DEBUG_START(ClassificationInterpreter::show)
  std::cout << index << "th class (total " << color_class_[index].size() << "):\n";
  this->showWithRepresentative(index, N);
  DEBUG_END(ClassificationInterpreter::show)
}/// ClassificationInterpreter::show

}/// namespace PlanarGraphColoring
