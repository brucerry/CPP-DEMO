// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <vector>
using namespace std;

// time: O(n^3)
// space: O(k)

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4)
      return {};
    
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> solution;
    vector<int> state;
    kSum(nums, target, solution, state, 0, 4);
    return solution;
  }
  
private:
  void kSum(vector<int>& nums, int target, vector<vector<int>>& solution, vector<int>& state, int start, int k) {
    if (k > 2) {
      for (int i = start; i < nums.size() - k + 1; i++) {
        if (i > start and nums[i-1] == nums[i])
          continue;
        state.emplace_back(nums[i]);
        kSum(nums, target - nums[i], solution, state, i + 1, k - 1);
        state.pop_back();
      }
      return;
    }
    
    int l = start, r = nums.size() - 1;
    while (l < r) {
      int twoSum = nums[l] + nums[r];
      if (twoSum < target)
        l++;
      else if (twoSum > target)
        r--;
      else {
        state.emplace_back(nums[l]);
        state.emplace_back(nums[r]);
        solution.emplace_back(state);
        state.pop_back();
        state.pop_back();
        
        l++;
        while (l < r and nums[l-1] == nums[l])
          l++;
      }
    }
  }
};