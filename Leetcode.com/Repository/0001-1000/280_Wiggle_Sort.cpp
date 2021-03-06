// https://leetcode.com/problems/wiggle-sort/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (((i & 1) and nums[i-1] > nums[i]) or
          (!(i & 1) and nums[i-1] < nums[i]))
        swap(nums[i-1], nums[i]);
    }
  }
};