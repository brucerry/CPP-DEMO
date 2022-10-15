// https://leetcode.com/problems/create-components-with-same-value/

#include <vector>
#include <numeric>
using namespace std;

// sum = sum of nums
// time: O(n * sqrt(sum))
// space: O(n)

class Solution {
public:
  int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    int result = 0;
    for (int components = 1; components * components <= sum; components++) {
      if (sum % components == 0) {
        int comp = components;
        dfs(nums, graph, sum / components, 0, -1, comp);
        if (comp == 0)
          result = max(result, components - 1);

        comp = sum / components;
        dfs(nums, graph, components, 0, -1, comp);
        if (comp == 0)
          result = max(result, sum / components - 1);
      }
    }

    return result;
  }

private:
  int dfs(vector<int>& nums, vector<vector<int>>& graph, int avg, int node, int prev, int& comp) {
    int sum = nums[node];
    for (const int& neighbor : graph[node]) {
      if (neighbor != prev) {
        sum += dfs(nums, graph, avg, neighbor, node, comp);
      }
    }

    if (avg == sum) {
      comp--;
      return 0;
    }

    return sum;
  }
};