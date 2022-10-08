// https://leetcode.com/problems/replace-elements-in-an-array/

#include <vector>
using namespace std;

// n = size of nums
// m = size of operations
// time: O(n + m)
// space: O(max(nums))

class Solution {
public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    int valIndex[1000001];
    for (int i = 0; i < nums.size(); i++) {
      valIndex[nums[i]] = i;
    }

    for (const auto& op : operations) {
      int oldval = op[0], newval = op[1];
      int i = valIndex[oldval];
      nums[i] = newval;
      valIndex[newval] = i;
    }

    return nums;
  }
};