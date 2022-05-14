// https://leetcode.com/problems/integer-break/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp (n + 1);
    dp[1] = 1;
    
    for (int num = 2; num <= n; num++) {
      for (int i = 1; i < num; i++) {
        dp[num] = max(dp[num], i * max(num - i, dp[num - i]));
      }
    }
    
    return dp[n];
  }
};