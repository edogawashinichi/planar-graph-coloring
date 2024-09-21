/// relation_builder.cxx 

#include "relation_builder.h"

namespace PlanarGraphColoring {

/*
void Colorer::analyzeIsomorphismByVerticesAndColors(const BirkhoffDiamond& bd, ColorResults* color_results) {
  std::cout << "---------start vertices&&colors----------\n";
  //DisjointSet ds(color_results->results_.size());
  RelationGraph rg(color_results);
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
  std::unordered_map<int, int> map;
  std::unordered_map<int, int> imap;
  for (int v = 0; v < vertices; ++v) {
    const int c = lhs.colors_.get(v);
    const int d = rhs.colors_.get(v);
    if (map.count(c) != imap.count(d)) return false;
    if (!map.count(c)) {
      map[c] = d;
      imap[d] = c;
    } else if (map[c] != d) {
      return false;
    }
  }
  std::cout << "isomorphismBoundaryColoringByColors map:\n";
  for (const auto& kv : map) {
    std::cout << kv.first << ":" << kv.second << " ";
  }
  std::cout << "\n";
  return true;
}///Colorer::isomorphismBoundaryColoringByColors

bool Colorer::isomorphismBoundaryColoringByVertices(const ColorResult& lhs, const ColorResult& rhs, const BirkhoffDiamond& bd) {
  for (int i = 0; i < bd.vertex_symmetry_.mappers_.size(); ++i) {
    const auto& mapper = bd.vertex_symmetry_.mappers_[i];
    BitRep tmp;
    lhs.colors_.transform(mapper, &tmp);
    if (tmp.equal(rhs.colors_)) {
      {std::cout << "isomorphismBoundaryColoringByVertices i=" << i << "\n";
      tmp.show(bd.k_);
      rhs.colors_.show(bd.k_);}
      return true;
    }
  }/// for mappers
  return false;
}/// Colorer::isomorphismBoundaryColoringByVertices
*/

}/// namespace PlanarGraphColoring
