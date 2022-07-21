// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_set>
using namespace std;

// time; O(n)
// space: O(n)

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> numSet;
    
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (r - l > k)
        numSet.erase(nums[l++]);
      if (numSet.count(nums[r]))
        return true;
      numSet.insert(nums[r]);
    }
    return false;
  }
};