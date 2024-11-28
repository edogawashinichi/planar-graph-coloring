/// digraph_result.h

#pragma once

#include "../basic/digraph.h"
#include <memory>

namespace PlanarGraphColoring {

class DigraphResult {
public:
  DigraphResult();
  Digraph* getVertex();
  const Digraph* getVertexConst() const;
  Digraph* getColor();
  const Digraph* getColorConst() const;
  Digraph* getVertexColor();
  const Digraph* getVertexColorConst() const;
  Digraph* getKempe();
  const Digraph* getKempeConst() const;
  Digraph* getVertexColorKempe();
  const Digraph* getVertexColorKempeConst() const;
  void setSize(const size_t n);
  void show() const;
protected:
  std::unique_ptr<Digraph> vertex_;
  std::unique_ptr<Digraph> color_;
  std::unique_ptr<Digraph> vertex_color_;
  std::unique_ptr<Digraph> kempe_;
  std::unique_ptr<Digraph> vertex_color_kempe_;
};/// class DigraphResult

}/// namespace PlanarGraphColoring
