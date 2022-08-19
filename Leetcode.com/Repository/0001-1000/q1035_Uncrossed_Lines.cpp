// https://leetcode.com/problems/uncrossed-lines/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)
class DP_1D {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int dp[501] {};
    for (int r = nums1.size() - 1; r >= 0; r--) {
      int prev = 0;
      
      for (int c = nums2.size() - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (nums1[r] == nums2[c])
          dp[c] = 1 + prev;
        else
          dp[c] = max(dp[c], dp[c+1]);
        
        prev = tmp;
      }
    }
    return dp[0];
  }
};

// time: O(r * c)
// space: O(r * c)
class DP_2D {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int dp[501][501] {};
    for (int r = nums1.size() - 1; r >= 0; r--) {
      for (int c = nums2.size() - 1; c >= 0; c--) {
        if (nums1[r] == nums2[c])
          dp[r][c] = 1 + dp[r+1][c+1];
        else
          dp[r][c] = max(dp[r+1][c], dp[r][c+1]);
      }
    }
    return dp[0][0];
  }
};

// time: O(r * c)
// space: O(r * c)
class TopDownMemo {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int memo[500][500];
    memset(memo, -1, sizeof(memo));
    return solve(nums1, nums2, 0, 0, memo);
  }
  
private:
  int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, int memo[500][500]) {
    if (i >= nums1.size() or j >= nums2.size())
      return 0;
    
    if (memo[i][j] != -1)
      return memo[i][j];
    
    if (nums1[i] == nums2[j])
      return memo[i][j] = 1 + solve(nums1, nums2, i + 1, j + 1, memo);
    
    return memo[i][j] = max(solve(nums1, nums2, i + 1, j, memo), solve(nums1, nums2, i, j + 1, memo));
  }
};