// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_set>
using namespace std;

// time; O(n)
// space: O(n)

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> set;
    int l = 0, r = 0;
    
    while (r < nums.size() && r <= k) {
      if (set.count(nums[r])) return true;
      set.emplace(nums[r]);
      r++;
    }
    
    while (r < nums.size()) {
      set.erase(nums[l]);
      if (set.count(nums[r])) return true;
      set.emplace(nums[r]);
      r++;
      l++;
    }
    
    return false;
  }
};