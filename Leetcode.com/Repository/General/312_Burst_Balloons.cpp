// https://leetcode.com/problems/burst-balloons/

#include <vector>
using namespace std;

// time: O(n^3)
// space: O(n^2)
class TopDownMemo {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> memo (n, vector<int>(n, -1));
    return solve(nums, 0, n - 1, memo);
  }
  
private:
  int solve(vector<int>& nums, int l, int r, vector<vector<int>>& memo) {
    if (l > r)
      return 0;
    
    if (memo[l][r] != -1)
      return memo[l][r];
    
    for (int i = l; i <= r; i++) {
      int leftcoin = l - 1 < 0 ? 1 : nums[l-1];
      int rightcoin = r + 1 >= nums.size() ? 1 : nums[r+1];
      int totalcoin = nums[i] * leftcoin * rightcoin + solve(nums, l, i-1, memo) + solve(nums, i+1, r, memo);
      memo[l][r] = max(memo[l][r], totalcoin);
    }
    
    return memo[l][r];
  }
};

// time: O(n^3)
// space: O(n^2)
class BottomUpDP {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    
    nums.emplace(nums.begin(), 1);
    nums.emplace(nums.end(), 1);
    vector<vector<int>> dp (n + 2, vector<int>(n + 2));
    
    for (int l = n; l >= 1; l--) {
      for (int r = 1; r <= n; r++) {
        if (l > r)
          continue;
        
        for (int i = l; i <= r; i++) {
          int totalcoin = nums[i] * nums[l-1] * nums[r+1] + dp[l][i-1] + dp[i+1][r];
          dp[l][r] = max(dp[l][r], totalcoin);
        }
      }
    }
    
    return dp[1][n];
  }
};