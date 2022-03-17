// https://leetcode.com/problems/sort-colors/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int i = 0;

    while (i <= right) {
      if (nums[i] == 0) {
        swap(nums[i], nums[left]);
        left++;
      }
      else if (nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
        i--;
      }
      i++;
    }
  }
};