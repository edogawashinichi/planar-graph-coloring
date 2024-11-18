/// dijkstra.cxx

#include "dijkstra.h"
#include <queue>
#include <vector>

namespace PlanarGraphColoring {

bool Dijkstra::run(const size_t start, const size_t end, const Digraph& digraph, DirectedPath* path) {
  DEBUG_START(Dijkstra::run)
  INFO_2VAR(start, end)
  /// 0. init environment
  std::list<DijkstraNode> list;
  std::priority_queue<DijkstraNode*, std::vector<DijkstraNode*>, DijkstraComparer> queue;
  std::vector<DijkstraNode*> visited(digraph.size(), nullptr);
  bool res = false;
  /// 1. init first node
  list.push_back(DijkstraNode(start));
  queue.push(&(list.back()));
  visited[start] = &(list.back());
  /// 2. main loop
  while (!queue.empty()) {
    /// 2.1 get top node - must be the best
    auto top = queue.top();
    queue.pop();
    if (PGC__DEBUG_MODE) {
      std::cout << "top:  ";
      top->show();
    }
    /// 2.2 find end node
    if (top->index_ == end) {
      DEBUG << "break\n";
      res = true;
      break;
    }
    /// 2.3 all successors of top node
    for (const auto successor : digraph.getSuccessors(top->index_)) {
      DEBUG << "successor: " << successor;
      if (nullptr == visited[successor]) {
        DEBUG << " not visited\n";
        /// 2.3.1 successor not visited (not in list)
        list.push_back(DijkstraNode(successor, top->length_ + 1.0f, top));
        queue.push(&(list.back()));
        visited[successor] = &(list.back());
        if (PGC__DEBUG_MODE) list.back().show();
      } else if (top->length_ + 1.0f < visited[successor]->length_) {
        DEBUG << " visited can be optimized\n";
        if (PGC__DEBUG_MODE) {
          DEBUG << "before:\n";
          visited[successor]->show();
        }
        /// 2.3.2 successor visited (already in list)
        ///       can be optimized through top
        visited[successor]->length_ = top->length_ + 1.0f;
        visited[successor]->prev_ = top;
        if (PGC__DEBUG_MODE) {
          DEBUG << "after:\n";
          visited[successor]->show();
        }
      } else {
        DEBUG << " visited cannot be optimized\n";
      }
    }/// for
  }/// while
  /// 3. get the best path
  path->clear();
  if (res) this->retrieve(list, path);
  DEBUG_END(Dijkstra::run)
  return res;
}/// Dijkstra::run

void Dijkstra::retrieve(const std::list<DijkstraNode>& list, DirectedPath* path) {
  /// assuming: list not empty
  DEBUG_START(Dijkstra::retrieve)
  const DijkstraNode* cur = &(list.back());
  auto& res = path->vertices_;
  do {
    if (PGC__DEBUG_MODE) cur->show();
    res.insert(res.begin(), cur->index_);
    cur = cur->prev_;
  } while (cur != nullptr);
  DEBUG_END(Dijkstra::retrieve)
}

}/// namespace PlanarGraphColoring
