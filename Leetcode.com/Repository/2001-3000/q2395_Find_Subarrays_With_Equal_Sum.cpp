// https://leetcode.com/problems/find-subarrays-with-equal-sum/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> sumSet;
    for (int i = 1; i < nums.size(); i++) {
      int sum = nums[i-1] + nums[i];
      if (!sumSet.emplace(sum).second)
        return true;
    }
    return false;
  }
};