/// birkhoff_diamond_colorer.h

#pragma once

#include "colorer.h"
#include "../topology/birkhoff_diamond.h"

namespace PlanarGraphColoring {

class BirkhoffDiamondColorer : public Colorer<BIRKHOFF_DIAMOND_BOUNDARY_SIZE, BIRKHOFF_DIAMOND_INTERIOR_SIZE> {
public:
  virtual void run(const Graph& birkhoff_diamond, ConfigurationColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE, BIRKHOFF_DIAMOND_INTERIOR_SIZE>* birkhoff_diamond_coloring_result) override;
  virtual void colorBoundary(const Graph& birkhoff_diamond, ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* colorings) override;
  virtual void colorInterior(const Graph& birkhoff_diamond, const ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>& boundary_colorings, ColoringResult<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* interior_colorings);
  bool colorInterior(const BirkhoffDiamond& birkhoff_diamond, const Coloring<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>& boundary_coloring, Coloring<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* interior_coloring);
protected:
  void colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t start_index, const size_t end_index, Coloring<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* coloring, ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* colorings);
  bool colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t start_index, const size_t end_index, Coloring<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* coloring);
  /* Coloring<> deduce */
  void getUnusedColors(const BirkhoffDiamond& birkhoff_diamond, const Coloring& coloring, const size_t vertex, const Coloring* unused_colors);
  /// TODO: delete the following
  /*
  virtual void run(const Graph& birkhoff_diamond, ColorResult* output) override;
  virtual void colorBoundary(const Graph& birkhoff_diamond, ColorResult* output) override;
  virtual bool colorInterior(const Graph& birkhoff_diamond, ColorResult* output) override;
  bool colorInterior(const BirkhoffDiamond& birkhoff_diamond, ColorRepresentation* color);
  */
  /*
  void colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, std::vector<size_t>& state, const size_t cur_index, ColorResult* output);
  bool colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t cur_index, ColorRepresentation* color);
  */
};/// class BirkhoffDiamondColorer

}/// namespace PlanarGraphColoring
