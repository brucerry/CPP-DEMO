// https://leetcode.com/problems/contains-duplicate-ii/

#include <vector>
#include <unordered_set>
using namespace std;

// time; O(n)
// space: O(n)

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> numsSet;
    
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (r - l > k)
        numsSet.erase(nums[l++]);
      
      if (l < r and r - l <= k and numsSet.count(nums[r]))
        return true;
      numsSet.emplace(nums[r]);
    }
    
    return false;
  }
};