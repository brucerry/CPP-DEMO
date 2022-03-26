// https://leetcode.com/problems/find-pivot-index/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (leftSum == sum - leftSum - nums[i]) return i;
      leftSum += nums[i];
    }
    return -1;
  }
};