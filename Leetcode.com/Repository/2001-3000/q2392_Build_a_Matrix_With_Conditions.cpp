// https://leetcode.com/problems/build-a-matrix-with-conditions/

#include <vector>
using namespace std;

// r = size of rowConditions
// c = size of colConditions
// time: O(k + r + c)
// space: O(k^2)

class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> rowGraph (k + 1);
    for (const auto& rc : rowConditions) {
      int node1 = rc[0], node2 = rc[1];
      rowGraph[node1].emplace_back(node2);
    }
    
    vector<vector<int>> colGraph (k + 1);
    for (const auto& cc : colConditions) {
      int node1 = cc[0], node2 = cc[1];
      colGraph[node1].emplace_back(node2);
    }
    
    vector<pair<int, int>> indices (k + 1); // { rowIndex, colIndex };
    if (!topologicalSort(rowGraph, indices, true) or !topologicalSort(colGraph, indices, false))
      return {};
    
    vector<vector<int>> result (k, vector<int>(k));
    for (int node = 1; node <= k; node++) {
      auto [ r, c ] = indices[node];
      result[r][c] = node;
    }
    
    return result;
  }
  
private:
  bool topologicalSort(vector<vector<int>>& graph, vector<pair<int, int>>& indices, bool is_row) {
    int n = graph.size();
    
    vector<int> parentCount (n);
    for (int parent = 1; parent < n; parent++) {
      for (const int& node : graph[parent]) {
        parentCount[node]++;
      }
    }
    
    vector<int> ready;
    for (int node = 1; node < n; node++) {
      if (parentCount[node] == 0)
        ready.emplace_back(node);
    }
    
    int len = 0;
    while (ready.size()) {
      int node = ready.back();
      ready.pop_back();
      
      if (is_row)
        indices[node].first = len++;
      else
        indices[node].second = len++;
      
      for (const int& neighbor : graph[node]) {
        if (--parentCount[neighbor] == 0)
          ready.emplace_back(neighbor);
      }
    }
    
    return len == n - 1;
  }
};