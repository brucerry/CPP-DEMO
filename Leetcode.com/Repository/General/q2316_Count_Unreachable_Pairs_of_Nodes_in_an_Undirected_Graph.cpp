// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <vector>
using namespace std;

// time: O(e + n)
// space: O(e + n)

class Solution {
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      graph[node1].emplace_back(node2);
      graph[node2].emplace_back(node1);
    }
    
    vector<char> visited (n);
    long long result = (long long)n * (n - 1) >> 1;
    for (int node = 0; node < n; node++) {
      if (visited[node] == 0) {
        int count = exploreMember(graph, node, visited);
        result -= (long long)count * (count - 1) >> 1;
      }
    }
    
    return result;
  }
  
private:
  int exploreMember(vector<vector<int>>& graph, int node, vector<char>& visited) {
    if (visited[node])
      return 0;
    
    visited[node] = 1;
    
    int count = 1;
    for (const int& neighbor : graph[node]) {
      if (visited[neighbor] == 0)
        count += exploreMember(graph, neighbor, visited);
    }
    
    return count;
  }
};