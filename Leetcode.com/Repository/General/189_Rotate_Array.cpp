// https://leetcode.com/problems/rotate-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};