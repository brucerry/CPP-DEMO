// https://leetcode.com/problems/burst-balloons/

#include <vector>
using namespace std;

// time: O(n^3)
// space: O(n^2)
class TopDownMemo {
public:
  int maxCoins(vector<int>& nums) {
    vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), -1));
    return solve(nums, 0, nums.size() - 1, dp);
  }
  
private:
  int solve(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
    if (left > right)
      return 0;
    
    if (dp[left][right] != -1)
      return dp[left][right];
    
    for (int i = left; i <= right; i++) {
      int leftCoin = left - 1 < 0 ? 1 : nums[left - 1];
      int rightCoin = right + 1 >= nums.size() ? 1 : nums[right + 1];
      int totalCoin = nums[i] * leftCoin * rightCoin + solve(nums, left, i - 1, dp) + solve(nums, i + 1, right, dp);
      dp[left][right] = max(dp[left][right], totalCoin);
    }
    
    return dp[left][right];
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
          int totalCoin = nums[i] * nums[l-1] * nums[r+1] + dp[l][i-1] + dp[i+1][r];
          dp[l][r] = max(dp[l][r], totalCoin);
        }
      }
    }
    
    return dp[1][n];
  }
};