// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

#include <vector>
using namespace std;

// time: O(n * k)
// space: O(n * k)

class Solution {
public:
  int rearrangeSticks(int n, int k) {
    vector<vector<long>> dp (n + 1, vector<long>(k + 1));
    dp[1][1] = 1;
    
    for (int r = 2; r <= n; r++) {
      for (int c = 1; c <= k; c++) {
        dp[r][c] = (dp[r-1][c-1] + dp[r-1][c] * (r - 1)) % 1000000007;
      }
    }
    
    return dp[n][k] % 1000000007;
  }
};