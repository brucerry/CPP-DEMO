#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


unordered_map<string, vector<string>> buildGraph(std::vector<std::tuple<std::string, std::string>> edges) {
  unordered_map<string, vector<string>> graph;
  for (auto [ a, b ] : edges) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

bool undirectedPath(unordered_map<string, vector<string>> graph, unordered_set<string> &visited, string src, string dst) {
  if (src == dst) return true;
  
  if (visited.count(src)) return false;
  visited.insert(src);
  
  for (auto neighbor : graph[src]) {
    if (undirectedPath(graph, visited, neighbor, dst)) return true;
  }
  
  return false;
}


bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst) {
  unordered_map<string, vector<string>> graph = buildGraph(edges);
  unordered_set<string> visited;
  return undirectedPath(graph, visited, src, dst);
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}