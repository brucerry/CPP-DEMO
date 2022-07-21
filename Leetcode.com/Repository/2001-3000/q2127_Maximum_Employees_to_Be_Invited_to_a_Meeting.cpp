// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    
    vector<vector<int>> graph (n);
    for (int node = 0; node < n; node++) {
      if (favorite[favorite[node]] != node)
        graph[favorite[node]].emplace_back(node);
    }
    
    vector<char> visited (n);
    int employee = 0;
    for (int node = 0; node < n; node++) {
      if (favorite[favorite[node]] == node)
        employee += traverse(graph, node, visited);
    }
    
    for (int node = 0; node < n; node++) {
      int count = 0, cur = node;
      while (visited[cur] == 0) {
        visited[cur] = 1;
        count++;
        cur = favorite[cur];
      }
      for (int x = node; x != cur; x = favorite[x])
        count--;
      employee = max(employee, count);
    }
    
    return employee;
  }
  
private:
  int traverse(vector<vector<int>>& graph, int node, vector<char>& visited) {
    visited[node] = 1;
    
    int count = 0;
    for (const int& neighbor : graph[node]) {
      count = max(count, traverse(graph, neighbor, visited));
    }
    
    return count + 1;
  }
};