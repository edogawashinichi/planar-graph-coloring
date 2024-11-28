/// dijkstra.cxx

#include "dijkstra.h"
#include <queue>
#include <vector>

/// 0. init environment
#define INIT_ENVIRONMENT \
std::list<DijkstraNode> list; \
std::priority_queue<DijkstraNode*, std::vector<DijkstraNode*>, DijkstraComparer> queue; \
std::vector<DijkstraNode*> visited(digraph.size(), nullptr);

/// 1. init first node
#define INIT_FIRST_NODE \
list.push_back(DijkstraNode(start)); \
queue.push(&(list.back())); \
visited[start] = &(list.back());

/// 2.1 get top node - must be the best
#define GET_TOP_NODE \
auto top = queue.top(); \
queue.pop(); \
if (PGC__DEBUG_MODE) { \
  std::cout << PURPLE << "top" << RESET << ":  "; \
  top->show(); \
}

/// 2.3 all successors of top node
#define ALL_SUCCESSORS_OF_TOP_NODE \
for (const auto successor : digraph.getSuccessors(top->index_)) { \
  DEBUG << CYAN << "successor" << RESET << ": " << successor; \
  if (nullptr == visited[successor]) { \
    DEBUG << " not visited\n"; \
    /* 2.3.1 successor not visited (not in list) */ \
    list.push_back(DijkstraNode(successor, top->length_ + digraph.weight(), top)); \
    queue.push(&(list.back())); \
    visited[successor] = &(list.back()); \
    if (PGC__DEBUG_MODE) list.back().show(); \
  } else if (top->length_ + digraph.weight() < visited[successor]->length_) { \
    DEBUG << " visited can be optimized\n"; \
    if (PGC__DEBUG_MODE) { \
      std::cout << "before:\n"; \
      visited[successor]->show(); \
    } \
    /* 2.3.2 successor visited (already in list) */ \
    /*       can be optimized through top */ \
    visited[successor]->length_ = top->length_ + digraph.weight(); \
    visited[successor]->prev_ = top; \
    if (PGC__DEBUG_MODE) { \
      std::cout << "after:\n"; \
      visited[successor]->show(); \
    } \
  } else { \
    DEBUG << " visited cannot be optimized\n"; \
  } \
}/* for */

namespace PlanarGraphColoring {

/// TODO: consider weighted digraph with negative cycle

bool Dijkstra::run(const size_t start, const size_t end, const Digraph& digraph, DirectedPath* path) {
  DEBUG_START(Dijkstra::run)
  INFO_2VAR(start, end)
  /// 0. init environment
  INIT_ENVIRONMENT
  bool res = false;
  /// 1. init first node
  INIT_FIRST_NODE
  /// 2. main loop
  while (!queue.empty()) {
    /// 2.1 get top node - must be the best
    GET_TOP_NODE
    /// 2.2 find end node
    if (top->index_ == end) {
      DEBUG << "break\n";
      res = true;
      break;
    }
    /// 2.3 all successors of top node
    ALL_SUCCESSORS_OF_TOP_NODE
  }/// while
  /// 3. get the best path
  path->clear();
  if (res) {
    this->retrieve(visited[end], path);
    INFO << "best path exist:\n";
    path->show();
  } else {
    INFO << "best path not exist!\n"; 
  }
  DEBUG_END(Dijkstra::run)
  return res;
}/// Dijkstra::run

void Dijkstra::run(const size_t start, const Digraph& digraph, DirectedPathResult* paths) {
  DEBUG_START(Dijkstra::run)
  INFO_VAR(start)
  /// 0. init environment
  INIT_ENVIRONMENT
  /// 1. init first node
  INIT_FIRST_NODE
  /// 2. main loop
  while (!queue.empty()) {
    /// 2.1 get top node - must be the best
    GET_TOP_NODE
    /// 2.3 all successors of top node
    ALL_SUCCESSORS_OF_TOP_NODE
  }/// while
  /// 3. get all best paths
  this->retrieve(list, paths);
  INFO << "all best paths:\n";
  paths->show();
  DEBUG_END(Dijkstra::run)
}/// Dijkstra::run

void Dijkstra::retrieve(const std::list<DijkstraNode>& list, DirectedPathResult* paths) {
  for (const auto& ele : list) {
    DirectedPath path;
    this->retrieve(&ele, &path);
    paths->insert(path);
  }
}/// Dijkstra::retrieve

void Dijkstra::retrieve(const DijkstraNode* end_ptr, DirectedPath* path) {
  /// assuming: end_ptr != nullptr
  DEBUG_START(Dijkstra::retrieve)
  const DijkstraNode* cur = end_ptr;
  auto& res = path->vertices_;
  do {
    if (PGC__DEBUG_MODE) cur->show();
    res.insert(res.begin(), cur->index_);
    cur = cur->prev_;
  } while (cur != nullptr);
  DEBUG_END(Dijkstra::retrieve)
}

}/// namespace PlanarGraphColoring
