// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> LIScount (nums.size(), {1, 1}); // (len, count)
    int lenLIS = 0, ans = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
      int maxLen = 1, maxCount = 1;

      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] < nums[j]) {
          auto& [ len, count ] = LIScount[j];
          if (len + 1 > maxLen) {
            maxLen = len + 1;
            maxCount = count;
          }
          else if (len + 1 == maxLen) {
            maxCount += count;
          }
        }
      }

      if (maxLen > lenLIS) {
        lenLIS = maxLen;
        ans = maxCount;
      }
      else if (maxLen == lenLIS) {
        ans += maxCount;
      }

      LIScount[i] = { maxLen, maxCount };
    }

    return ans;
  }
};