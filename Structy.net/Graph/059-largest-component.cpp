#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

int largestComponent(std::unordered_map<int, std::vector<int>> graph, int node, unordered_set<int>& visited) {
  if (visited.count(node)) return 0;
  visited.insert(node);
  
  int count = 1;
  for (auto neighbor : graph[node]) {
    count += largestComponent(graph, neighbor, visited);
  }
  
  return count;
}


int largestComponent(std::unordered_map<int, std::vector<int>> graph) {
  unordered_set<int> visited;
  
  int largest = 0;
  for (auto pair : graph) {
    int count = largestComponent(graph, pair.first, visited);
    largest = max(largest, count);
  }
  
  return largest;
}



void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}