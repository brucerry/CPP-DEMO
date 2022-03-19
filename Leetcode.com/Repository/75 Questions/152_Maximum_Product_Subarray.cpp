// https://leetcode.com/problems/maximum-product-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int curMax = 1, curMin = 1;

    for (int& num : nums) {
      int tmpMax = curMax * num;
      int tmpMin = curMin * num;
      curMax = max({tmpMax, tmpMin, num});
      curMin = min({tmpMax, tmpMin, num});
      ans = max(ans, curMax);
    }

    return ans;
  }
};