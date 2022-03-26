// https://leetcode.com/problems/perfect-squares/

#include <vector>
using namespace std;

// time: O(n * sqrt(n))
// space: O(n)

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp (n + 1, n);
    dp[0] = 0;

    for (int target = 1; target <= n; target++) {
      for (int i = 1; i * i <= target; i++) {
        dp[target] = min(dp[target], 1 + dp[target - i * i]);
      }
    }

    return dp[n];
  }
};