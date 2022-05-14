// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int LIScount = 0, maxLen = 0;
    int n = nums.size();
    vector<pair<int, int>> dp (n); // len, count
    
    for (int i = n - 1; i >= 0; i--) {
      int len = 1, count = 1;
      
      for (int j = i + 1; j < n; j++) {
        auto [ len_j, count_j ] = dp[j];
        if (nums[i] < nums[j]) {
          if (len < len_j + 1) {
            len = len_j + 1;
            count = count_j;
          }
          else if (len == len_j + 1) {
            count += count_j;
          }
        }
      }
      
      if (len > maxLen) {
        maxLen = len;
        LIScount = count;
      }
      else if (len == maxLen)
        LIScount += count;
      
      dp[i] = { len, count };
    }
    
    return LIScount;
  }
};