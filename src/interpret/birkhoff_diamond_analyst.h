/// birkhoff_diamond_analyst.h

#pragma once

#include "analyst.h"

/// TODO
// this is a classifer
// we also need a shortest path router

namespace PlanarGraphColoring {

class BirkhoffDiamondAnalyst : public Analyst {
public:
  virtual void reasonByVertex(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByColor(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByKempe(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByVertexColorKempe(const RelationManager& relation_manager, Interpreter* interpreter) override;
};/// class BirkhoffDiamondAnalyst

}/// namespace PlanarGraphColoring
