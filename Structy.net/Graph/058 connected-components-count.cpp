#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;


bool connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph, int node, unordered_set<int> &visited) {
  if (visited.count(node)) return false;
  visited.insert(node);
  
  for (auto neighbor : graph[node]) {
    connectedComponentsCount(graph, neighbor, visited);
  }
  
  return true;
}


int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) {
  unordered_set<int> visited;
  
  int count = 0;
  for (auto pair : graph) {
    if (connectedComponentsCount(graph, pair.first, visited)) count++;
  }
  
  return count;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}