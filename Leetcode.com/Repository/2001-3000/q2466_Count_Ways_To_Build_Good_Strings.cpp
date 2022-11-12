// https://leetcode.com/problems/count-ways-to-build-good-strings/

// time: O(high)
// space: O(high)

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int result = 0, mod = 1e9 + 7, dp[100001] {};
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
      if (i >= zero)
        dp[i] = (dp[i] + dp[i - zero]) % mod;
      if (i >= one)
        dp[i] = (dp[i] + dp[i - one]) % mod;
      if (i >= low)
        result = (result + dp[i]) % mod;
    }
    return result;
  }
};