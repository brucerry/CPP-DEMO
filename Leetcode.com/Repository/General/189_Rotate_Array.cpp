// https://leetcode.com/problems/rotate-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  void rotate(vector<int>& nums, int k) {    
    if ((k %= nums.size()) == 0)
      return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};