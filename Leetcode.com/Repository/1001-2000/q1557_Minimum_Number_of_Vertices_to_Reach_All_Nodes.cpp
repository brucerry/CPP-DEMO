// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n)

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> result, reachable (n);
    for (const auto& e : edges)
      reachable[e[1]] = 1;
    for (int node = 0; node < n; node++) {
      if (!reachable[node])
        result.emplace_back(node);
    }
    return result;
  }
};