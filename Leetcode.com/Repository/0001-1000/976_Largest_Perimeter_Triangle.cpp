// https://leetcode.com/problems/largest-perimeter-triangle/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    for (int i = 0; i < nums.size() - 3 + 1; i++) {
      if (nums[i] < nums[i+1] + nums[i+2])
        return nums[i] + nums[i+1] + nums[i+2];
    }
    return 0;
  }
};