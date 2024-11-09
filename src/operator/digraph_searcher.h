/// digraph_searcher.h

#include "searcher.h"
#include "../basic/digraph.h"
#include "digraph_searcher_result.h"

namespace PlanarGraphColoring {

class DigraphSearcher : public Searcher {
public:
  virtual void dfs(const Structure& digraph, SearcherResult* digraph_searcher_result) override;
  virtual void bfs(const Structure& digraph, SearcherResult* digraph_searcher_result) override;
  virtual void greedy(const Structure& digraph, SearcherResult* digraph_searcher_result) override;
  virtual void dijkstra(const Structure& digraph, SearcherResult* digraph_searcher_result) override;
protected:
  void dfsHelper(const Digraph& digraph, const size_t vertex, std::vector<int>& visited, DigraphSearcherResult* digraph_searcher_result); 
};/// class DigraphSearcher

}/// namespace PlanarGraphColoring
