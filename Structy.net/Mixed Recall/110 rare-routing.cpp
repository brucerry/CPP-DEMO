#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<int, vector<int>> buildGraph(std::vector<std::vector<int>> roads) {
  unordered_map<int, vector<int>> graph;
  for (auto road : roads) {
    int a = road[0];
    int b = road[1];
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

bool explore(unordered_map<int, vector<int>> graph,
            int node,
            int prevNode,
            unordered_set<int> &visited) {
  if (visited.count(node)) return false;
  visited.insert(node);
  
  for (auto neighbor : graph[node]) {
    if (neighbor != prevNode && !explore(graph, neighbor, node, visited)) return false;
  }
  
  return true;
}

bool rareRouting(int n, std::vector<std::vector<int>> roads) {
  unordered_map<int, vector<int>> graph = buildGraph(roads);
  unordered_set<int> visited;
  
  bool valid = explore(graph, 0, -1, visited);
  
  return valid && visited.size() == n;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}