/// analyst.h

#pragma once

#include "../relation/relation_manager.h"
#include "interpreter.h"
/// TODO: get rid of Kempe in RelationManager

namespace PlanarGraphColoring {

class Analyst {
public:
  virtual void reasonByVertex(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByColor(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, const Interpreter& input, const size_t i, const size_t j, const size_t k, Interpreter* output) = 0;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, const size_t i, Interpreter* output, Interpreter* input) = 0;
  //virtual void reasonByKempe(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  //virtual void reasonByVertexColorKempe(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
};/// class Analyst

}/// namespace PlanarGraphColoring
