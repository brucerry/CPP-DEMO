// https://leetcode.com/problems/first-missing-positive/


#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:

  // solution would be [ 1, ..., nums.size()+1 ]


  int firstMissingPositive(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] < 0) nums[i] = 0;
    }

    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      if (0 <= index && index < nums.size()) {
        if (nums[index] > 0) {
          nums[index] *= -1;
        } else if (nums[index] == 0) {
          nums[index] = -(nums.size()+1);
        }
      }
    }

    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i-1] >= 0) return i;
    }

    return nums.size() + 1;
  }
};