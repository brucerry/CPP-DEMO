// https://leetcode.com/problems/coin-change-2/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(a * c)
  // space: O(a)
  int change(int amount, vector<int>& coins) {
    int dp[amount + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int c = coins.size() - 1; c >= 0; c--) {
      int nextDP[amount + 1];
      copy(dp, dp + amount + 1, nextDP);
      for (int a = 1; a <= amount; a++) {
        int remain = a - coins[c];
        if (remain >= 0) {
          nextDP[a] += nextDP[remain];
        }
      }
      copy(nextDP, nextDP + amount + 1, dp);
    }

    return dp[amount];
  }
};