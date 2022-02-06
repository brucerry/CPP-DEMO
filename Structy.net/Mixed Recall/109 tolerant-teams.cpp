#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<string>> buildGraph(std::vector<std::tuple<std::string, std::string>> rivalries) {
  unordered_map<string, vector<string>> graph;
  for (auto [ a, b ] : rivalries) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  return graph;
}

bool canColor(unordered_map<string, vector<string>> graph,
             string node,
             unordered_map<string, bool> &colored,
             bool color) {
  if (colored.count(node)) return colored[node] == color;
  
  colored[node] = color;
  
  for (auto neighbor : graph[node]) {
    if (!canColor(graph, neighbor, colored, !color)) return false;
  }
  
  return true;
}

bool tolerantTeams(std::vector<std::tuple<std::string, std::string>> rivalries) {
  unordered_map<string, vector<string>> graph = buildGraph(rivalries);
  unordered_map<string, bool> colored;
  for (auto pair : graph) {
    if (colored.count(pair.first) == 0 && !canColor(graph, pair.first, colored, true)) return false;
  }
  return true;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}