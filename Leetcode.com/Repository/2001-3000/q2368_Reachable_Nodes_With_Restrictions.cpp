// https://leetcode.com/problems/reachable-nodes-with-restrictions/

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      graph[node1].emplace_back(node2);
      graph[node2].emplace_back(node1);
    }
    
    vector<char> visited (n);
    for (const int& node : restricted)
      visited[node] = 1;
    
    int visitedCount = 0;
    
    queue<int> queue; // node
    queue.emplace(0);
    
    while (queue.size()) {
      int node = queue.front();
      queue.pop();
      
      visited[node] = 1;
      visitedCount++;
      
      for (const int& neighbor : graph[node]) {
        if (visited[neighbor] == 0)
          queue.emplace(neighbor);
      }
    }
    
    return visitedCount;
  }
};