// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> complementMap;

    for (int i = 0; i < nums.size(); i++) {
      int cmplt = target - nums[i];
      if (complementMap.count(nums[i])) return { complementMap[nums[i]], i };
      complementMap[cmplt] = i;
    }

    return {};
  }
};