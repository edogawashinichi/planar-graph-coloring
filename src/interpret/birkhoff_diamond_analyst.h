/// birkhoff_diamond_analyst.h

#pragma once

#include "analyst.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondAnalyst : public Analyst {
public:
  virtual void reasonByVertex(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByColor(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, Interpreter* interpreter) override;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, const Interpreter& classification_interpreter, const size_t i, const size_t j, const size_t k, Interpreter* routing_interpreter) override;
  virtual void reasonByVertexColor(const RelationManager& relation_manager, const Interpreter& classification_interpreter, const size_t i, const size_t j, Interpreter* kempe_interpreter) override;
  //virtual void reasonByKempe(const RelationManager& relation_manager, Interpreter* interpreter) override;
  //virtual void reasonByVertexColorKempe(const RelationManager& relation_manager, Interpreter* interpreter) override;
};/// class BirkhoffDiamondAnalyst

}/// namespace PlanarGraphColoring
