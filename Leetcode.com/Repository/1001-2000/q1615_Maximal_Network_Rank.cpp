// https://leetcode.com/problems/maximal-network-rank/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    char connected[100][100] {}, counts[100] {};
    for (const auto& rd : roads) {
      int u = rd[0], v = rd[1];
      connected[u][v] = connected[v][u] = 1;
      counts[u]++;
      counts[v]++;
    }

    int result = 0;
    for (int u = 0; u < n; u++) {
      for (int v = u + 1; v < n; v++) {
        result = max(result, counts[u] + counts[v] - connected[u][v]);
      }
    }

    return result;
  }
};