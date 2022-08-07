// https://leetcode.com/problems/ugly-number-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp (n + 1);
    dp[1] = 1;
    
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = min({ dp[p2] * 2, dp[p3] * 3, dp[p5] * 5 });
      p2 += dp[i] == dp[p2] * 2 ? 1 : 0;
      p3 += dp[i] == dp[p3] * 3 ? 1 : 0;
      p5 += dp[i] == dp[p5] * 5 ? 1 : 0;
    }
    
    return dp[n];
  }
};