// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    // index 0->min 1->max
    int found[2] {}, lastIndex[2] = {}, validIndex = -1;
    long result = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < minK or nums[i] > maxK) {
        found[0] = found[1] = false;
        validIndex = -1;
        continue;
      }
      if (validIndex == -1 and minK <= nums[i] and nums[i] <= maxK)
        validIndex = i;
      if (nums[i] == minK) {
        found[0] = true;
        lastIndex[0] = i;
      }
      if (nums[i] == maxK) {
        found[1] = true;
        lastIndex[1] = i;
      }
      if (found[0] and found[1]) {
        result += min(lastIndex[0], lastIndex[1]) - validIndex + 1;
      }
    }
    
    return result;
  }
};