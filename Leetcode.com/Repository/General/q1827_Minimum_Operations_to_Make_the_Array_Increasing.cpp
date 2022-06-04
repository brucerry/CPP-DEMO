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
      if (nums[i-1] < nums[i])
        continue;
      int diff = nums[i-1] - nums[i];
      op += diff + 1;
      nums[i] += diff + 1;
    }
    return op;
  }
};