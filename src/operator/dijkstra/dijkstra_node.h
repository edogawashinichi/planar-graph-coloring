/// dijkstra_node.h

#pragma once

#include "../../basic/notation.h"

namespace PlanarGraphColoring {

struct DijkstraNode {
  size_t index_;
  float length_;/// from start to index
  DijkstraNode* prev_;
  DijkstraNode() = delete;
  DijkstraNode(const size_t i) : index_(i), length_(0), prev_(nullptr) {}
  DijkstraNode(const size_t i, const float l, DijkstraNode* p) : index_(i), length_(l), prev_(p) {}
  void show() const {
    TEST_INFO
    INFO << "index: " << index_ << " length: " << length_;
    if (nullptr == prev_) {
      INFO << " prev: nullptr\n";
    } else {
      INFO << " prev: " << (prev_->index_) << "\n";
    }
  }/// show
};/// struct DijkstraNode

struct DijkstraComparer {
  bool operator()(const DijkstraNode* lhs, const DijkstraNode* rhs) {
    if (rhs == nullptr) return true;
    if (lhs == nullptr) return false;
    return lhs->length_ > rhs->length_;
  }/// operator()
};/// struct DijkstraComparer

}/// namespace PlanarGraphColoring
