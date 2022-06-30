// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    int l = 0, r = nums.size() - 1, move = 0;
    while (l < r) {
      move += nums[r] - nums[l];
      l++;
      r--;
    }
    return move;
  }
};