// https://leetcode.com/problems/minimum-height-trees/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> parentCount (n);
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      graph[node1].emplace_back(node2);
      graph[node2].emplace_back(node1);
      parentCount[node1]++;
      parentCount[node2]++;
    }
    
    vector<int> leaves;
    for (int node = 0; node < n; node++) {
      if (parentCount[node] == 0 or parentCount[node] == 1)
        leaves.emplace_back(node);
    }
    
    int remainNodes = n;
    while (remainNodes > 2) {
      vector<int> newLeaves;
      for (const int& leave : leaves) {
        for (const int& neighbor : graph[leave]) {
          if (--parentCount[neighbor] == 1)
            newLeaves.emplace_back(neighbor);
        }
      }
      remainNodes -= leaves.size();
      leaves = newLeaves;
    }
    
    return leaves;
  }
};