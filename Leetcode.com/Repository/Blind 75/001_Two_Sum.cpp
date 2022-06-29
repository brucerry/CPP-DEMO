// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> diffIndex; // diff, index
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (diffIndex.count(diff))
        return { i, diffIndex[diff] };
      diffIndex[nums[i]] = i;
    }
    return { -1, -1 };
  }
};