/// analyst.h

#pragma once

#include "../relation/relation_manager.h"
#include "interpreter.h"

namespace PlanarGraphColoring {

class Analyst {
public:
  virtual void reasonByVertex(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByColor(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByKempe(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
  virtual void reasonByVertexColorKempe(const RelationManager& relation_manager, Interpreter* interpreter) = 0;
};/// class Analyst

}/// namespace PlanarGraphColoring
