#include <vector>
#include <tuple>
#include <unordered_map>
#include <iostream>
using namespace std;


unordered_map<int, vector<int>> buildGraph(std::vector<std::tuple<int, int>> prereqs, int numCourses) {
  unordered_map<int, vector<int>> graph;
  for (auto [ a, b ] : prereqs) {
    graph[a].push_back(b);
  }
  for (int i = 0; i < numCourses; i++) {
    if (graph.count(i) == 0) {
      graph[i] = {};
    }
  }
  return graph;
}


int traverse(unordered_map<int, vector<int>> graph,
            unordered_map<int, int> &distance,
            int node) {
  if (distance.count(node)) return distance[node];
  
  int longest = 0;
  for (auto neighbor : graph[node]) {
    int dist = traverse(graph, distance, neighbor);
    longest = max(longest, dist);
  }
  
  distance[node] = longest + 1;
  return distance[node];
}



int semestersRequired(int numCourses, std::vector<std::tuple<int, int>> prereqs) {
  unordered_map<int, vector<int>> graph = buildGraph(prereqs, numCourses);
  unordered_map<int, int> distance;
  
  // comment this ???
  // no need to initialize 1 is still work
  // because traverse(...) would add 1 at the end of the recursion
  //
  //for (auto pair : graph) {
  //  if (pair.second.size() == 0) {
  //    distance[pair.first] = 1;
  //  }
  //}
  
  for (auto pair : graph) {
    traverse(graph, distance, pair.first);
  }
  
  int longest = 0;
  for (auto pair : distance) {
    longest = max(longest, pair.second);
  }
  
  return longest;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}