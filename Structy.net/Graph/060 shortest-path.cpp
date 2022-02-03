#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<string, vector<string>> buildGraph(std::vector<std::tuple<std::string, std::string>> edges) {
  unordered_map<string, vector<string>> graph;  
  for (auto [ a, b ] : edges) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }    
  return graph;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) {
  unordered_map<string, vector<string>> graph = buildGraph(edges);
  unordered_set<string> visited;
  queue<tuple<string, int>> queue;
  queue.push({nodeA, 0});
  visited.insert(nodeA);
  
  while (queue.size()) {
    auto [ node, dist ] = queue.front();
    queue.pop();
    if (node == nodeB) return dist;
    
    for (auto neighbor : graph[node]) {
      if (visited.count(neighbor) == 0) {
        visited.insert(neighbor);
        queue.push({neighbor, dist + 1});
      }
    }
  }
  
  return -1;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}