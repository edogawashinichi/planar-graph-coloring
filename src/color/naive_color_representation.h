/// naive_color_representation.h

/// realize color representation by the naive method
/// using int to represent {0, 1, 2, 3}

#pragma once

#include "color_representation.h"
#include <unordered_map>

namespace PlanarGraphColoring {

class NaiveColorRepresentation : public ColorRepresentation {
protected:
  std::unordered_map<size_t, int> index2color_;
public:
  NaiveColorRepresentation();
  NaiveColorRepresentation(const std::vector<int>& colors);

  virtual size_t size() const override;
  virtual int get(const size_t index) const override; 
  virtual std::vector<int> getVector() const override;
  virtual void set(const size_t index, const int color) override;
  virtual void reset(const size_t index) override;
  virtual void show() const override;
  virtual bool valid() const override;
};/// class NaiveColorRepresentation

}/// namespace PlanarGraphColoring
