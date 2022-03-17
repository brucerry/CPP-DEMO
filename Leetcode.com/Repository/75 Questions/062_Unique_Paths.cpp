// https://leetcode.com/problems/unique-paths/

#include <vector>
using namespace std;

// time: O(m * n)
// space: O(n)

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp (n, 1);

    for (int r = m - 2; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        if (c < n - 1) dp[c] += dp[c + 1];
      }
    }

    return dp[0];
  }
};