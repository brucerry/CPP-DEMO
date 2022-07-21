// https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int movesToMakeZigzag(vector<int>& nums) {
    int n = nums.size(), result[2] = {};
    for (int i = 0; i < n; i++) {
      int leftval = i ? nums[i-1] : INT_MAX;
      int rightval = i + 1 < n ? nums[i+1] : INT_MAX;
      result[i & 1] += max(0, nums[i] - min(leftval, rightval) + 1);
    }
    return min(result[0], result[1]);
  }
};