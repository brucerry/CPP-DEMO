// https://leetcode.com/problems/maximum-star-sum-of-a-graph/

#include <vector>
#include <algorithm>
using namespace std;

// time: Amortized O(e + n * log(n))
// space: O(e)

class Solution {
public:
  int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    int n = vals.size();
    
    vector<vector<int>> graph (n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1];
      graph[a].emplace_back(vals[b]);
      graph[b].emplace_back(vals[a]);
    }
    
    for (int i = 0; i < n; i++) {
      sort(graph[i].rbegin(), graph[i].rend());
      graph[i].resize(min(k, (int)graph[i].size()));
    }
    
    int res = *max_element(vals.begin(), vals.end());
    
    for (int i = 0; i < n; i++) {
      int sum = vals[i];
      for (const int& val : graph[i]) {
        sum += max(0, val);
      }
      res = max(res, sum);
    }
    
    return res;
  }
};