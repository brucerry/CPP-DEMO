// https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minOperations(vector<int>& nums) {
    int op = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i-1] >= nums[i]) {
        int inc = nums[i-1] - nums[i] + 1;
        op += inc;
        nums[i] += inc;
      }
    }
    return op;
  }
};