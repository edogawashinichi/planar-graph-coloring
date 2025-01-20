/// birkhoff_diamond.h

//             2 --------- 1
//            /|\         /|\
//           / | \       / | \
//          /  |  \     /  |  \
//         /   |   \   /   |   \
//        /    |    \ /    |    \
//       /     |     7     |     \
//      /      |    /|\    |      \
//     /       |   / | \   |       \
//    /        |  /  |  \  |        \
//   /         | /   |   \ |         \
//  /          |/    |    \|          \
// 3 --------- 8     |     6 --------- 0
//  \          |\    |    /|          /
//   \         | \   |   / |         /
//    \        |  \  |  /  |        /
//     \       |   \ | /   |       /
//      \      |    \|/    |      /
//       \     |     9     |     /
//        \    |    / \    |    /
//         \   |   /   \   |   /
//          \  |  /     \  |  /
//           \ | /       \ | /
//            \|/         \|/
//             4 --------- 5

#pragma once

#include "ring.h"
#include "../algebra/symmetry.h"

namespace PlanarGraphColoring {

class BirkhoffDiamond: public Ring {
public:
  Ring shrinkToRing() const;
public:
  BirkhoffDiamond();
  virtual const VII getBoundarySeparatedVertexPairs(const size_t i, const size_t j) const override;
  inline bool isBoundary(const size_t vertex) const {
    return vertex < k_;
  }
  inline const VertexSymmetry& getVS() const {
    return vertex_symmetry_;
  }
  inline std::vector<size_t> getVS(const size_t index) const {
    return vertex_symmetry_.get(index);
  }
  inline std::vector<size_t> getBBN(const size_t vertex) const {
    return boundary_backward_neighbors_.count(vertex) ? boundary_backward_neighbors_.at(vertex) : std::vector<size_t>();
  }
  inline std::vector<size_t> getIBN(const size_t vertex) const {
    return interior_backward_neighbors_.count(vertex) ? interior_backward_neighbors_.at(vertex) : std::vector<size_t>();
  }
  inline const std::vector<std::pair<size_t, size_t>>& getBNV() const {
    return boundary_nonadjacent_vertices_;
  }
  std::vector<std::pair<size_t, size_t>> getBoundaryCutVertices(const size_t u, const size_t v) const;
  virtual void show() const override;

protected:
  /// TODO: shunt to BirkhoffDiamondCalculator
  /// TODO: so much data make this class complicated
  /// TODO: to ease constructor
  VertexSymmetry vertex_symmetry_;
  std::unordered_map<size_t, std::vector<size_t>> boundary_backward_neighbors_;
  std::unordered_map<size_t, std::vector<size_t>> interior_backward_neighbors_;
  std::vector<std::pair<size_t, size_t>> boundary_nonadjacent_vertices_;
};/// class BirkhoffDiamond

}/// namespace PlanarGraphColoring
