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
      if (diffIndex.count(nums[i]))
        return { i, diffIndex[nums[i]] };
      int diff = target - nums[i];
      diffIndex[diff] = i;
    }
    
    return { -1, -1 };
  }
};