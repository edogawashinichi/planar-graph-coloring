/// kempe_interpreter.h

#pragma once

#include "interpreter.h"
#include "../color/kempe/kempe_chain.h"
#include "routing_interpreter.h"

namespace PlanarGraphColoring {

class KempeInterpreter : public Interpreter {
public:
  virtual void show(std::ostream& cout) const override;
  inline RoutingInterpreter& getSeparatingRoute() {
    return separating_route_;
  }
  inline RoutingInterpreter& getSeparatedRoute() {
    return separated_route_;
  }
  inline KempeChainResult& getKempeChainResult() {
    return kempe_chain_result_;
  }
  inline const KempeChainResult& constKempeChainResult() const {
    return kempe_chain_result_;
  }
  void setClass(const size_t i, const size_t j, const size_t k);
  inline void setColoring(const NaiveColorRepresentation& coloring) {
    coloring_ = coloring;
  }
protected:
  size_t class_, separating_class_, separated_class_;
  NaiveColorRepresentation coloring_;
  KempeChainResult kempe_chain_result_;
  RoutingInterpreter separating_route_;
  RoutingInterpreter separated_route_;
};/// class KempeInterpreter

}/// namespace PlanarGraphColoring
