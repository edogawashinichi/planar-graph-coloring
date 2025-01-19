/// direct_product.h

/// direct product of two groups: G X H = {(g, h): for each g in G, for each h in H}
/// realization: maintain group G, group H, direct product of index

#pragma once

#include "../basic/structure/dimension_two_vector.h"
#include "group.h"
#include <memory>

namespace PlanarGraphColoring {

template<typename T, typename S>
/// DEPRECATED: class DirectProduct : public Group<std::pair<T, S>> {
class DirectProduct : public DimensionTwoVector<size_t> {
public:
  inline DirectProduct() = default;
  inline DirectProduct(const size_t TN, const size_t SN) {
    g_ = std::make_unique(Group<T>(TN));
    h_ = std::make_unique(Group<S>(SN));
    DimensionTwoVector<size_t>::set(g_->size(), h_->size());
  }/// constructor
  inline virtual size_t size() const override {
    return g_->size() * h_->size();
  }/// size
  inline virtual void show() const override {
    TEST_INFO
    g_->show();
    h_->show();
    DimensionTwoVector<size_t>::show();
  }/// show
protected:
  std::unique_ptr<Group<T>> g_;
  std::unique_ptr<Group<S>> h_;
};/// class DirectProduct

}/// namespace PlanarGraphColoring
