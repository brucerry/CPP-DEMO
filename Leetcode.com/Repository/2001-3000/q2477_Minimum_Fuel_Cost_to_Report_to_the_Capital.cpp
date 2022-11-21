// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    vector<int> graph[100001];
    for (const auto& r : roads) {
      int u = r[0], v = r[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    long res = 0;
    dfs(graph, seats, res, -1, 0);
    return res;
  }

private:
  int dfs(vector<int>* graph, int seats, long& res, int prev, int cur) {
    int ppl = 1;
    for (const int& nei : graph[cur]) {
      if (prev != nei)
        ppl += dfs(graph, seats, res, cur, nei);
    }
    int cars = (ppl + seats - 1) / seats;
    res += cur ? cars : 0;
    return ppl;
  }
};