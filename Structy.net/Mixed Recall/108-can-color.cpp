#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

bool canColor(std::unordered_map<std::string, std::vector<std::string>> graph,
             string node,
             unordered_map<string, bool> &colored,
             bool color) {
  if (colored.count(node)) {
    return colored[node] == color;
  }
  colored[node] = color;
  
  for (auto neighbor : graph[node]) {
    if (!canColor(graph, neighbor, colored, !color)) return false;
  }
  
  return true;
}

bool canColor(std::unordered_map<std::string, std::vector<std::string>> graph) {
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