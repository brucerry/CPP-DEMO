#include <vector>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
using namespace std;


bool hasCycle(std::unordered_map<int, std::vector<int>> graph,
              int node,
              unordered_set<int> &visiting,
              unordered_set<int> &visited) {
  if (visiting.count(node)) return true;
  if (visited.count(node)) return false;
  
  visiting.insert(node);
  
  for (auto neighbor : graph[node]) {
    if (hasCycle(graph, neighbor, visiting, visited)) return true;
  }
  
  visiting.erase(node);
  visited.insert(node);
  
  return false;
}

unordered_map<int, vector<int>> buildGraph(std::vector<std::tuple<int, int>> prereqs) {
  unordered_map<int, vector<int>> graph;
  for (auto [ a, b ] : prereqs) {
    graph[a].push_back(b);
  }
  return graph;
}


bool prereqsPossible(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
  unordered_map<int, vector<int>> graph = buildGraph(prereqs);
  unordered_set<int> visited;
  unordered_set<int> visiting;
  
  for (auto pair : graph) {
    if (hasCycle(graph, pair.first, visiting, visited)) return false;
  }
  
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}