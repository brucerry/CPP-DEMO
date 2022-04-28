// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> LIScount (nums.size()); // len, count
    LIScount.back() = { 1, 1 };
    
    int maxLen = 1, maxCount = 1;
    
    for (int i = nums.size() - 2; i >= 0; i--) {
      int len = 1, count = 1;
      
      for (int j = i + 1; j < nums.size(); j++) {
        auto [ curLen, curCount ] = LIScount[j];
        
        if (nums[i] < nums[j]) {
          if (curLen + 1 > len) {
            len = curLen + 1;
            count = curCount;
          }
          else if (curLen + 1 == len) {
            count += curCount;
          }
        }
      }
      
      if (len > maxLen) {
        maxLen = len;
        maxCount = count;
      }
      else if (len == maxLen) {
        maxCount += count;
      }
      
      LIScount[i] = { len, count };
    }
    
    return maxCount;
  }
};