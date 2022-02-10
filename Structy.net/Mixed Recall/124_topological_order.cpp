#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

std::vector<std::string> topologicalOrder(std::unordered_map<std::string, std::vector<std::string>> graph) {
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
  
  vector<string> order;
  while (ready.size()) {
    string node = ready.back();
    ready.pop_back();
    order.push_back(node);
    
    for (auto neighbor : graph[node]) {
      if (--numParents[neighbor] == 0) ready.push_back(neighbor);
    }
  }
  
  return order;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}