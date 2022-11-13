// https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/

#include <vector>
#include <numeric>
using namespace std;

// lcm = time for lcm()
// time: O(n^2 * lcm)
// space: O(1)

class Solution {
public:
  int subarrayLCM(vector<int>& nums, int k) {
    int n = nums.size(), result = 0;
    for (int i = 0; i < n; i++) {
      int LCM = nums[i];
      for (int j = i; j < n; j++) {
        LCM = lcm(LCM, nums[j]);
        if (LCM > k)
          break;
        result += LCM == k;
      }
    }
    return result;
  }
};