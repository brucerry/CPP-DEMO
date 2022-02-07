#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


bool hasCycle(std::unordered_map<char, std::vector<char>> graph,
              char node,
              unordered_set<char> &visiting,
              unordered_set<char> &visited) {
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


bool hasCycle(std::unordered_map<char, std::vector<char>> graph) {
  unordered_set<char> visiting;
  unordered_set<char> visited;
  
  for (auto pair : graph) {
    if (hasCycle(graph, pair.first, visiting, visited)) return true;
  }
  
  return false;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}