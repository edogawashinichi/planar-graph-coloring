/// graph_searcher.h

#pragma once

#include "searcher.h"

namespace PlanarGraphColoring {

class GraphSearcher : public Searcher {
public:
  virtual void dfs(const Structure& structure, SearcherResult* searcher_result) override;
  virtual void bfs(const Structure& structure, SearcherResult* searcher_result) override;
  virtual void bibfs(const Structure& structure, const  II& vertex_pair, SearcherResult* searcher_result) override;
  virtual void greedy(const Structure& structure, SearcherResult* searcher_result) override;
  virtual void dijkstra(const Structure& structure, SearcherResult* searcher_result) override;
};/// class GraphSearcher

}/// namespace PlanarGraphColoring
