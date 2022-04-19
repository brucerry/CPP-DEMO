// https://leetcode.com/problems/sort-colors/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    
    for (int i = l; i <= r; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[l]);
        l++;
      }
      else if (nums[i] == 2) {
        swap(nums[i], nums[r]);
        r--;
        i--;
      }
    }
  }
};