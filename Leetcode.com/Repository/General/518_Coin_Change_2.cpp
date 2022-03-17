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

    for (int& coin : coins) {
      for (int a = 1; a <= amount; a++) {
        int remain = a - coin;
        if (remain >= 0) {
          dp[a] += dp[remain];
        }
      }
    }

    return dp[amount];
  }
};