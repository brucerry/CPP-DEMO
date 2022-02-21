/*
  n = # of courses (nodes)
  e = # of prerequisites (edges)
  time: O(n + e)
  space: O(n + e)
*/

#include <vector>
#include <iostream>
using namespace std;

bool hasCycle(vector<vector<int>>& graph, int node, vector<int>& visited) {
  if (visited[node] == 1) return true; // visiting
  if (visited[node] == 2) return false; // visited

  visited[node] = 1;

  for (auto neighbor : graph[node]) {
    if (hasCycle(graph, neighbor, visited)) return true;
  }

  visited[node] = 2;

  return false;
}

bool canFinish(int n, vector<vector<int>>& prerequisites) {
  vector<vector<int>> graph (n);
  for (auto courses : prerequisites) {
    int a = courses[0];
    int b = courses[1];
    graph[b].push_back(a);
  }

  vector<int> visited (n, 0);

  for (int node = 0; node < n; node++) {
    if (hasCycle(graph, node, visited)) return false;
  }

  return true;
}

int main() {
  int n = 6;
  vector<vector<int>> prerequisites1 {{0,1}, {3,0}, {1,3}, {2,1}, {4,1}, {4,2}, {5,3}, {5,4}};
  vector<vector<int>> prerequisites2 {{3,0}, {1,3}, {2,1}, {4,1}, {4,2}, {5,3}, {5,4}};

  cout << (canFinish(n, prerequisites1) ? "true" : "false") << endl; // false
  cout << (canFinish(n, prerequisites2) ? "true" : "false") << endl; // true
}