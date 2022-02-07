#include <vector>
#include <unordered_map>
using namespace std;


int traverse(std::unordered_map<char, std::vector<char>> graph,
             unordered_map<char, int> &distance,
             char node) {
  if (distance.count(node)) return distance[node];
  
  int longest = 0;
  for (auto neighbor : graph[node]) {
    int count = traverse(graph, distance, neighbor);
    longest = max(longest, count);
  }
  
  distance[node] = longest + 1;
  return distance[node];
}



int longestPath(std::unordered_map<char, std::vector<char>> graph) {
  unordered_map<char, int> distance;
  for (auto pair : graph) {
    if (pair.second.size() == 0) {
      distance[pair.first] = 0;
    }
  }
  
  for (auto pair : graph) {
    traverse(graph, distance, pair.first);
  }
  
  int longest = 0;
  for (auto [ node, dist ] : distance) {
    longest = max(longest, dist);
  }
  
  return longest;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}