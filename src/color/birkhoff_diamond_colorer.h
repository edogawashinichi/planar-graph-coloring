/// birkhoff_diamond_colorer.h

#pragma once

#include "colorer.h"
#include "../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondColorer : public Colorer {
public:
  virtual void run(const Graph& birkhoff_diamond, ColorResult* output) override;
  virtual void colorBoundary(const Graph& birkhoff_diamond, ColorResult* output) override;
  virtual bool colorInterior(const Graph& birkhoff_diamond, ColorResult* output) override;
  bool colorInterior(const BirkhoffDiamond& birkhoff_diamond, ColorRepresentation* color);
protected:
  void colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, std::vector<int>& state, const size_t cur_index, ColorResult* output);
  bool colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t cur_index, ColorRepresentation* color);
/*
  void colorBoundaryBruteForce(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByColorsAndVertices(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByVerticesAndColors(const BirkhoffDiamond& bd, ColorResults* color_results);
  void analyzeIsomorphismByColors(ColorResults* color_results, DisjointSet* disjoint_set);
  void analyzeIsomorphismByVertices(const BirkhoffDiamond& bd, ColorResults* color_results, DisjointSet* disjoint_set);
  bool isomorphismBoundaryColoringByColors(const ColorResult& lhs, const ColorResult& rhs, const int vertices);
  bool isomorphismBoundaryColoringByVertices(const ColorResult& lhs, const ColorResult& rhs, const BirkhoffDiamond& bd);
  void append(const std::vector<int>& colors, ColorResults* color_results);
  void increase(std::vector<int>& colors);
  int isValid(const std::vector<int>& colors);*/
};/// class BirkhoffDiamondColorer

}/// namespace PlanarGraphColoring
