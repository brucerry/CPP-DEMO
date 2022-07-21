// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <vector>
using namespace std;

// time: O(2^n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n = graph.size();
    
    vector<vector<int>> solution;
    vector<int> state { 0 };
    solve(graph, solution, state, 0, n - 1);
    return solution;
  }
  
private:
  void solve(vector<vector<int>>& graph, vector<vector<int>>& solution, vector<int>& state, int src, int dst) {
    if (src == dst) {
      solution.emplace_back(state);
      return;
    }
    
    for (const int& neighbor : graph[src]) {
      state.emplace_back(neighbor);
      solve(graph, solution, state, neighbor, dst);
      state.pop_back();
    }
  }
};