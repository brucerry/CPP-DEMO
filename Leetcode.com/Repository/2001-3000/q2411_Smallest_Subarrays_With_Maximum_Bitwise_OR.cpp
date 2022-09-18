// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    int closest[30] {}, n = nums.size();
    vector<int> result (n, 1);
    
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < 30; j++) {
        if (nums[i] & (1 << j))
          closest[j] = i;
        result[i] = max(result[i], closest[j] - i + 1);
      }
    }
    
    return result;
  }
};