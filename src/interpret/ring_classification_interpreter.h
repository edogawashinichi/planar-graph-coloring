/// ring_classification_interpreter.h

/// TODO: delete classification_interpreter.h

#pragma once

#include "interpreter.h"
#include "../topology/ring.h"
#include "../topology/birkhoff_diamond.h"
#include "../color/ring_coloring_result.h"
#include "../color/colorer.h"
#include "../algebra/coloring_group/birkhoff_diamond_coloring_group.h"
#include "../algebra/coloring_group/birkhoff_diamond_coloring_actor.h"
#include "../algebra/coloring_group/coloring_orbit_result.h"
#include "../algebra/coloring_group/acc_coloring_orbit_result.h"

#define CLASS_CLASSIFICATION_INTERPRETER(Ring) \
class Ring##ClassificationInterpreter : public Interpreter { \
public: \
  inline Ring##ClassificationInterpreter() { \
    this->run(); \
  }/* constructor default */ \
  inline void run() { \
    Ring ring; \
    Colorer::getInstance().run(ring, &ring_colorings_); \
    Ring##ColoringGroup& group = Ring##ColoringGroup::getInstance(); \
    Ring##ColoringActor& actor = Ring##ColoringActor::getInstance(); \
    ColoringOrbitResult orbits; \
    actor.run(ring_colorings_, group, &orbits); \
    ColoringOrbitResult reduced_orbits; \
    orbits.removeDuplicate(&reduced_orbits); \
    acc_.set(reduced_orbits); \
  }/* run */ \
  inline void show(std::ostream& cout, const size_t index) const { \
    TEST_INFO \
    /* assuming: index valid */ \
    DEBUG_START(Ring##ClassificationInterpreter::show) \
    const ColoringInfo& info = acc_.getConst(index); \
    const size_t representative = info.representative(); \
    const size_t group_index = info.groupIndex(); \
    const size_t inverse_group_index = info.inverseGroupIndex(); \
    const RingColoring& index_coloring = ring_colorings_.getConst(index); \
    const RingColoring& representative_coloring = ring_colorings_.getConst(representative); \
    cout << "index: " << index << "\n"; \
    cout << "index_coloring:\n"; \
    index_coloring.showData(cout); \
    cout << "inverse_group_index: " << inverse_group_index << "\n"; \
    Ring##ColoringGroup::getInstance().show(cout, inverse_group_index); \
    cout << "representative: " << representative << "\n"; \
    cout << "representative_coloring:\n"; \
    representative_coloring.showData(cout); \
    cout << "group_index: " << group_index << "\n"; \
    Ring##ColoringGroup::getInstance().show(cout, group_index); \
    DEBUG_END(Ring##ClassificationInterpreter::show) \
  }/* show */ \
  inline void show(std::ostream& cout) const { \
    TEST_INFO \
    acc_.show(cout); \
  }/* show */ \
  inline friend std::ostream& operator<<(std::ostream& cout, const Ring##ClassificationInterpreter& obj) { \
    obj.show(cout); \
    return cout; \
  }/* friend operator<< */ \
protected: \
  RingColoringResult ring_colorings_; \
  AccColoringOrbitResult acc_; \
};/* class Ring##ClassificationInterpreter */

namespace PlanarGraphColoring {

CLASS_CLASSIFICATION_INTERPRETER(BirkhoffDiamond)

}/// namespace PlanarGraphColoring
