// https://leetcode.com/problems/coin-change-2/

#include <vector>
using namespace std;

// time: O(a * c)
// space: O(a)

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp (amount + 1, 0);
    dp[0] = 1;
    
    for (const int& coin : coins) {
      for (int a = 1; a <= amount; a++) {
        if (a >= coin) {
          dp[a] += dp[a - coin];
        }
      }
    }
    
    return dp[amount];
  }
};