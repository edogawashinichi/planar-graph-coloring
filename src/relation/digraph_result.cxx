/// DigraphResult.cxx

#include "digraph_result.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

DigraphResult::DigraphResult() {
  vertex_ = std::make_unique<Digraph>();
  color_ = std::make_unique<Digraph>();
  vertex_color_ = std::make_unique<Digraph>();
  kempe_ = std::make_unique<Digraph>();
  vertex_color_kempe_ = std::make_unique<Digraph>();
}/// DigraphResult::DigraphResult() {

void DigraphResult::setSize(const size_t n) {
  vertex_->setSize(n);
  color_->setSize(n);
  vertex_color_->setSize(n);
  kempe_->setSize(n);
  vertex_color_kempe_->setSize(n);
}/// DigraphResult::setSize

Digraph* DigraphResult::getVertex() {
  return vertex_.get();
}/// DigraphResult::getVertex
const Digraph* DigraphResult::getVertexConst() const{
  return vertex_.get();
}/// DigraphResult::getVertexConst

Digraph* DigraphResult::getColor() {
  return color_.get();
}/// DigraphResult::getColor
const Digraph* DigraphResult::getColorConst() const {
  return color_.get();
}/// DigraphResult::getColorConst

Digraph* DigraphResult::getVertexColor() {
  return vertex_color_.get();
}/// DigraphResult::getVertexColor
const Digraph* DigraphResult::getVertexColorConst() const {
  return vertex_color_.get();
}/// DigraphResult::getVertexColorConst

Digraph* DigraphResult::getKempe() {
  return kempe_.get();
}/// DigraphResult::getKempe
const Digraph* DigraphResult::getKempeConst() const {
  return kempe_.get();
}/// DigraphResult::getKempeConst

Digraph* DigraphResult::getVertexColorKempe() {
  return vertex_color_kempe_.get();
}/// DigraphResult::getVertexColorKempe
const Digraph* DigraphResult::getVertexColorKempeConst() const {
  return vertex_color_kempe_.get();
}/// DigraphResult::getVertexColorKempeConst

void DigraphResult::show() const {
  TEST_INFO
  INFO_START(DigraphResult::show)
  const size_t vertex_size = vertex_->size();
  const size_t vertex_arcs = vertex_->arcs();
  INFO_2VAR(vertex_size, vertex_arcs)
  const size_t color_size = color_->size();
  const size_t color_arcs = color_->arcs();
  INFO_2VAR(color_size, color_arcs)
  const size_t vertex_color_size = vertex_color_->size();
  const size_t vertex_color_arcs = vertex_color_->arcs();
  INFO_2VAR(vertex_color_size, vertex_color_arcs)
  const size_t kempe_size = kempe_->size();
  const size_t kempe_arcs = kempe_->arcs();
  INFO_2VAR(kempe_size, kempe_arcs)
  const size_t vertex_color_kempe_size = vertex_color_kempe_->size();
  const size_t vertex_color_kempe_arcs = vertex_color_kempe_->arcs();
  INFO_2VAR(vertex_color_kempe_size, vertex_color_kempe_arcs)
  INFO_END(DigraphResult::show)
}/// DigraphResult::show

}/// namespace PlanarGraphColoring
