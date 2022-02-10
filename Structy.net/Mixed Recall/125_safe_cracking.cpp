#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
using namespace std;

string topologicalOrder(std::unordered_map<std::string, std::vector<std::string>> graph) {
  unordered_map<string, int> numParents;
  for (auto [ node, neighbors ] : graph) {
    if (numParents.count(node) == 0) numParents[node] = 0;
    
    for (auto neighbor : neighbors) {
      numParents[neighbor]++;
    }
  }
  
  vector<string> ready;
  for (auto [ node, count ] : numParents) {
    if (count == 0) ready.push_back(node);
  }
  
  string order;
  while (ready.size()) {
    string node = ready.back();
    ready.pop_back();
    order += node;
    
    for (auto neighbor : graph[node]) {
      if (--numParents[neighbor] == 0) ready.push_back(neighbor);
    }
  }
  
  return order;
}

std::string safeCracking(std::vector<std::tuple<int, int>> hints) {
  unordered_map<string, vector<string>> graph;
  for (auto [ a, b ] : hints) {
    graph[to_string(a)].push_back(to_string(b));
  }
  return topologicalOrder(graph);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}