// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

#include <vector>
using namespace std;

// time: O(m * n)
// space: O(m * n)
class TopDownMemo {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> memo (m + 1, vector<int>(n + 1, INT_MIN));
    return solve(nums1, nums2, 0, 0, memo);
  }
  
private:
  int solve(vector<int>& nums1, vector<int>& nums2, int p1, int p2, vector<vector<int>>& memo) {
    if (p1 >= nums1.size() or p2 >= nums2.size())
      return INT_MIN;
    
    if (memo[p1][p2] != INT_MIN)
      return memo[p1][p2];
    
    int result = INT_MIN;
    int next = solve(nums1, nums2, p1+1, p2+1, memo);
    int take = nums1[p1] * nums2[p2] + max(0, next);
    int skip_p1 = solve(nums1, nums2, p1+1, p2, memo);
    int skip_p2 = solve(nums1, nums2, p1, p2+1, memo);
    
    result = max({
      result,
      take,
      skip_p1,
      skip_p2
    });
    
    return memo[p1][p2] = result;
  }
};

// time: O(m * n)
// space: O(m * n)
class DP_2D {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp (m + 1, vector<int>(n + 1, INT_MIN));
    
    for (int p1 = m - 1; p1 >= 0; p1--) {
      for (int p2 = n - 1; p2 >= 0; p2--) {
        int next = dp[p1+1][p2+1];
        int take = nums1[p1] * nums2[p2] + max(0, next);
        dp[p1][p2] = max(dp[p1][p2], take);
        dp[p1][p2] = max(dp[p1][p2], dp[p1+1][p2]);
        dp[p1][p2] = max(dp[p1][p2], dp[p1][p2+1]);
      }
    }
    
    return dp[0][0];
  }
};

// time: O(m * n)
// space: O(n)
class DP_1D {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> dp (n + 1, INT_MIN);
    
    for (int p1 = m - 1; p1 >= 0; p1--) {
      int prev = dp.back();
      
      for (int p2 = n - 1; p2 >= 0; p2--) {
        int tmp = dp[p2];
        
        int take = nums1[p1] * nums2[p2] + max(0, prev);
        dp[p2] = max(dp[p2], take);
        dp[p2] = max(dp[p2], dp[p2+1]);
        
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};