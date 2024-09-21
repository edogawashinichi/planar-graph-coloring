/// birkhoff_diamond_colorer.cxx

#include "birkhoff_diamond_colorer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/math.h"
#include "../basic/notation.h" 

namespace PlanarGraphColoring {

void BirkhoffDiamondColorer::run(const Graph& birkhoff_diamond, ColorResult* output) {
  colorBoundary(birkhoff_diamond, output);
  colorInterior(birkhoff_diamond, output);
}/// BirkhoffDiamondColorer::run

bool BirkhoffDiamondColorer::colorInterior(const Graph& birkhoff_diamond, ColorResult* output) {
  PGC__SHOW_ENDL("start colorInterior")
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  bool res = false;
  for (size_t i = 0; i < output->size(); ++i) {
    ColorRepresentation* color = output->get(i);
    bool tmp = colorInterior(derived, color);
    res = res || tmp;
    //res = res || colorInterior(derived, color);/// logic operation shortcut
  }
  output->show(20);
  PGC__SHOW_ENDL("end colorInterior")
  return res;
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInterior(const BirkhoffDiamond& birkhoff_diamond, ColorRepresentation* color) {
  return colorInteriorDFS(birkhoff_diamond, birkhoff_diamond.boundarySize(), color);
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t cur_index, ColorRepresentation* color) {
  if (cur_index == birkhoff_diamond.size()) return true;
  const auto& ibn = birkhoff_diamond.getIBN(cur_index);/// interior backward neighbors
  std::vector<int> used_colors(birkhoff_diamond.size(), UNDEF_COLOR);
  map(ibn, color->getVector(), &used_colors);
  const std::vector<int> all_colors(id(COLORS));
  std::vector<int> unused_colors;
  diff(all_colors, used_colors, &unused_colors);
  for (const auto unused_color : unused_colors) {
    color->set(cur_index, unused_color);
    bool res = colorInteriorDFS(birkhoff_diamond, cur_index + 1, color);
    if (res) return true;
    color->reset(cur_index);
  }/// for unused_colors
  return false;
}/// Colorer::colorInteriorDFS

void BirkhoffDiamondColorer::colorBoundary(const Graph& birkhoff_diamond, ColorResult* output) {
  PGC__SHOW_ENDL("start colorBoundary")
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  std::vector<int> state(derived.size(), UNDEF_COLOR);
  colorBoundaryDFS(derived, state, 0, output);
  PGC__SHOW_ENDL("output:")
  output->show(20);
  PGC__SHOW_ENDL("end colorBoundary")
}/// BirkhoffDiamondColorer::colorBoundary

void BirkhoffDiamondColorer::colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, std::vector<int>& state, const size_t cur_index, ColorResult* output) {
  //std::cout << "colorBoundaryDFS cur_index: " << cur_index << "\n";
  if (cur_index == birkhoff_diamond.boundarySize()) {
    output->append(state);
    return;
  }
  const auto& bbn = birkhoff_diamond.getBBN(cur_index);/// boundary_backward_neighbors
  std::vector<int> used_colors(bbn.size(), UNDEF_COLOR);
  map(bbn, state, &used_colors);
  const std::vector<int> all_colors(id(COLORS));
  std::vector<int> unused_colors;
  diff(all_colors, used_colors, &unused_colors);
  for (const auto unused_color : unused_colors) {
    state[cur_index] = unused_color;
    colorBoundaryDFS(birkhoff_diamond, state, cur_index + 1, output);
    state[cur_index] = UNDEF_COLOR;
  }/// for unused_colors
}/// BirkhoffDiamondColorer::colorBoundaryDFS

/*
void Colorer::analyzeIsomorphismByVerticesAndColors(const BirkhoffDiamond& bd, ColorResults* color_results) {
  std::cout << "---------start vertices&&colors----------\n";
  DisjointSet ds(color_results->results_.size());
  analyzeIsomorphismByVertices(bd, color_results, &ds);
  color_results->showValidIsomorphism(50);
  std::set<int> s = ds.getRoots();
  analyzeIsomorphismByColors(color_results, &ds);
  color_results->showValidIsomorphism(50);
  color_results->showValidIsomorphism(s);
  std::cout << "-----------end vertices&&colors----------\n";
}/// Colorer::analyzeIsomorphismByVerticesAndColors

void Colorer::analyzeIsomorphismByColorsAndVertices(const BirkhoffDiamond& bd, ColorResults* color_results) {
  std::cout << "---------start colors&&vertices----------\n";
  DisjointSet ds(color_results->results_.size());
  analyzeIsomorphismByColors(color_results, &ds);
  color_results->showValidIsomorphism(50);
  std::set<int> s = ds.getRoots();
  analyzeIsomorphismByVertices(bd, color_results, &ds);
  color_results->showValidIsomorphism(50);
  color_results->showValidIsomorphism(s);
  std::cout << "-----------end colors&&vertices----------\n";
}/// Colorer::analyzeIsomorphismByColorsAndVertices

void Colorer::analyzeIsomorphismByVertices(const BirkhoffDiamond& bd, ColorResults* color_results, DisjointSet* disjoint_set) {
  const int n = color_results->results_.size();
  for (int i = 0; i < n - 1; ++i) {
    const auto& result_i = (color_results->results_)[i];
    if (!result_i.valid_) continue;
    for (int j = i + 1; j < n; ++j) {
      const auto& result_j = (color_results->results_)[j];
      if (i==3&&j==264) {
        std::cout << "result_" << i << " result_" << j << ":\n";
        result_i.show(bd.k_);
        result_j.show(bd.k_);
      }
      if (!result_j.valid_) continue;
      if (!isomorphismBoundaryColoringByVertices(result_i, result_j, bd)) continue;
      disjoint_set->unite(i, j);
      if(i==3&&j==264)std::cout << "unite " << i << "," << j << "\n";
    }/// for j
  }/// for i
  for (int i = 0; i < n; ++i) {
    (color_results->results_)[i].isomorphism_ = disjoint_set->find(i);
  }
  std::cout << "analyzeIsomorphismByVertices disjoint set size: " << disjoint_set->n() << "\n";
}/// Colorer::analyzeIsomorphismByVertices

void Colorer::analyzeIsomorphismByColors(ColorResults* color_results, DisjointSet* disjoint_set) {
  const int n = color_results->results_.size();
  for (int i = 0; i < n - 1; ++i) {
    const auto& result_i = (color_results->results_)[i];
    if (!result_i.valid_) continue;
    for (int j = i + 1; j < n; ++j) {
      const auto& result_j = (color_results->results_)[j];
      if (!result_j.valid_) continue;
      if (!isomorphismBoundaryColoringByColors(result_i, result_j, color_results->vertices_)) continue;
      disjoint_set->unite(i, j);
      //if (i==3&&j==8)std::cout << "unite " << i << "," << j << "\n";
    }/// for j
  }/// for i
  for (int i = 0; i < n; ++i) {
    (color_results->results_)[i].isomorphism_ = disjoint_set->find(i);
  }
  std::cout << "analyzeIsomorphismByColors disjoint set size: " << (disjoint_set->n()) << "\n";
}/// Colorer::analyzeIsomorphismByColors

void Colorer::colorBoundaryBruteForce(const BirkhoffDiamond& bd, ColorResults* color_results) {
  color_results->vertices_ = bd.k_;
  std::vector<int> colors(bd.k_, 0);
  while (true) {
    if (colors[bd.k_ - 1] == COLORS) break;
    append(colors, color_results);
    increase(colors);
  }/// while true
}/// Colorer::colorBoundaryBruteForce

/// shall have the context of a BirkhoffDiamond
int Colorer::isValid(const std::vector<int>& colors) {
  const int n = colors.size();
  for (int i = 0; i < n - 1; ++i) {
    if (colors[i] == colors[i + 1]) return 0;
  }/// for
  return static_cast<int>(colors[0] != colors[n - 1]);
}/// Colorer::isValid

void Colorer::append(const std::vector<int>& colors, ColorResults* color_results) {
  const int valid = isValid(colors) ? 1 : 0;
  ///const int isomorphism = isomorphismTo(colors, *color_results);
  if (!valid) {
    ///std::cout << "invalid!\n";
    return;
  }
  color_results->append(colors, valid, -1);
  //std::cout << "valid: " << color_results->results_.size() << "\n";
}/// Colorer::append

void Colorer::increase(std::vector<int>& colors) {
  ++(colors[0]);
  for (int i = 0; i < colors.size() - 1; ++i) {
    if (colors[i] < COLORS) break;
    colors[i] = 0;
    ++(colors[i + 1]);
  }/// for
}/// Colorer::increase

bool Colorer::isomorphismBoundaryColoringByColors(const ColorResult& lhs, const ColorResult& rhs, const int vertices) {
  return lhs.colors_.isomorphismByColor(rhs.colors_, vertices);
}///Colorer::isomorphismBoundaryColoringByColors

bool Colorer::isomorphismBoundaryColoringByVertices(const ColorResult& lhs, const ColorResult& rhs, const BirkhoffDiamond& bd) {
  return lhs.colors_.isomorphismByVertex(rhs.colors_, bd);
}/// Colorer::isomorphismBoundaryColoringByVertices
*/
}/// namespace PlanarGraphColoring
