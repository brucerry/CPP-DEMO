// https://leetcode.com/problems/coin-change-2/

#include <vector>
using namespace std;

// time: O(amount * n)
// space: O(amount)

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int dp[5001] = { 1 };
    
    for (const int& coin : coins) {
        for (int a = 1; a <= amount; a++) {
            if (a >= coin)
                dp[a] += dp[a - coin];
        }
    }
    
    return dp[amount];
  }
};