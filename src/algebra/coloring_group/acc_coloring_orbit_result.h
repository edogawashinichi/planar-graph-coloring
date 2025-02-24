/// acc_coloring_orbit_result.h

#pragma once

#include "coloring_orbit_result.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class AccColoringOrbitResult {
public:
  inline AccColoringOrbitResult() = default;
  inline AccColoringOrbitResult(const ColoringOrbitResult& orbits) {
    this->set(orbits);
  }/// constructor
  inline void set(const ColoringOrbitResult& orbits) {
    for (size_t i = 0; i < orbits.size(); ++i) {
      const ColoringOrbit& orbit = orbits.getConst(i);
      for (size_t j = 0; j < orbit.size(); ++j) {
        const ColoringInfo& info = orbit.getConst(j);
        const size_t index = info.index();
        index2info_[index] = info;
      }/// for j
    }/// for i
  }/// constructor 
  inline ColoringInfo getConst(const size_t index) const {
    /* assuming: index valid */
    return index2info_.at(index);
  }/// getConst
  inline void show(std::ostream& cout) const {
    TEST_INFO
    const size_t size = index2info_.size();
    cout << "size: " << size << "\n";
  }/// show
protected:
  std::unordered_map<size_t, ColoringInfo> index2info_;
};/// class AccColoringOrbitResult

}/// namespace PlanarGraphColoring
