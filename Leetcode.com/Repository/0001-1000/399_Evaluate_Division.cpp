// https://leetcode.com/problems/evaluate-division/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// n = # of nodes
// e = # of edges = size of equations = size of values
// q = size of queries
// time: O(q * e)
// space: O(n + e)

class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> graph; // from, (to, val)
    for (int i = 0; i < equations.size(); i++) {
      string& from = equations[i][0];
      string& to = equations[i][1];
      double val = values[i];
      graph[from].emplace_back(to, val);
      graph[to].emplace_back(from, 1.0 / val);
    }
    
    int q = queries.size();
    vector<double> result (q);
    for (int i = 0; i < q; i++) {
      string& from = queries[i][0];
      string& to = queries[i][1];
      if (graph.count(from) == 0 or graph.count(to) == 0)
        result[i] = -1.0;
      else {
        unordered_set<string> visited;
        double ans = 1.0;
        result[i] = evaluate(graph, from, to, visited, ans) ? ans : -1.0;
      }
    }
    
    return result;
  }
  
private:
  bool evaluate(unordered_map<string, vector<pair<string, double>>>& graph, const string& src, const string& dst, unordered_set<string>& visited, double& ans) {
    if (src == dst)
      return true;
    
    if (visited.count(src))
      return false;
    
    visited.insert(src);
    
    for (const auto& [ neighbor, val ] : graph[src]) {
      if (evaluate(graph, neighbor, dst, visited, ans)) {
        ans *= val;
        return true;
      }
    }
    
    return false;
  }
};