/// relation_result.h

#pragma once

#include "relation.h"

namespace PlanarGraphColoring{

class RelationResult {
public:
  inline void append(const Relation& relation) {
    relations_.emplace_back(relation);
  }
  void show(const size_t n) const;
  inline size_t size() const {
    return relations_.size();
  }
protected:
  std::vector<Relation> relations_;
};/// class RelationResult

}/// namespace PlanarGraphColoring
