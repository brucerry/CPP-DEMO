// https://leetcode.com/problems/move-zeroes/

#include <vector>
using namespace std;

// time: O(n)
// time: O(1)

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
      if (nums[right]) {
        swap(nums[left++], nums[right]);
      }
    }
  }
};