// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)
class DP_1D {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int rows = nums1.size();
    int cols = nums2.size();
    int result = 0;
    
    vector<int> dp (cols + 1);
    
    for (int r = rows - 1; r >= 0; r--) {
      int prev = 0;
      
      for (int c = cols - 1; c >= 0; c--) {
        int tmp = dp[c];
        
        if (nums1[r] == nums2[c])
          dp[c] = 1 + prev;
        else
          dp[c] = 0;
        result = max(result, dp[c]);
        
        prev = tmp;
      }
    }
    
    return result;
  }
};

// time: O(r * c)
// space: O(r * c)
class DP_2D {
public:
  int findLength(vector<int>& nums1, vector<int>& nums2) {
    int rows = nums1.size();
    int cols = nums2.size();
    int result = 0;
    
    vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if (nums1[r] == nums2[c])
          dp[r][c] = 1 + dp[r+1][c+1];
        result = max(result, dp[r][c]);
      }
    }
    
    return result;
  }
};