// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> diffMap; // diff, index
    
    for (int i = 0; i < nums.size(); i++) {
      if (diffMap.count(nums[i])) return { diffMap[nums[i]], i };
      diffMap[target - nums[i]] = i;
    }
    
    return { -1, -1 };
  }
};