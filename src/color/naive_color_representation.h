/// naive_color_representation.h

/// realize color representation by the naive method
/// using size_t to represent {0, 1, 2, 3}

#pragma once

#include "color_representation.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class NaiveColorRepresentation : public ColorRepresentation {
protected:
  std::unordered_map<size_t, size_t> index2color_;
public:
  NaiveColorRepresentation();
  NaiveColorRepresentation(const NaiveColorRepresentation& rhs);
  NaiveColorRepresentation(const std::vector<size_t>& colors);
  NaiveColorRepresentation(NaiveColorRepresentation&& rhs);
  NaiveColorRepresentation& operator=(const NaiveColorRepresentation& rhs);
  NaiveColorRepresentation& operator=(NaiveColorRepresentation&& rhs);
  void set(const NaiveColorRepresentation& rhs);

  virtual size_t size() const override;
  inline std::unordered_map<size_t, size_t>& get() {
    return index2color_;
  }
  inline const std::unordered_map<size_t, size_t>& getConst() const {
    return index2color_;
  }
  virtual size_t get(const size_t index) const override; 
  virtual bool empty() const override;
  virtual std::vector<size_t> getVector() const override;
  virtual void set(const size_t index, const size_t color) override;
  virtual void reset(const size_t index) override;
  virtual void show(std::ostream& cout) const override;
  virtual bool valid() const override;
};/// class NaiveColorRepresentation

}/// namespace PlanarGraphColoring
