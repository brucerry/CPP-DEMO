// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <vector>
using namespace std;

// time: O(n * log(n) + n^3) => O(n^3)
// space: O(k)

class Solution {
private:
  void kSum(vector<int>& nums, vector<int>& candidate, int target, vector<vector<int>>& result, int k, int start) {
    if (k > 2) {
      for (int i = start; i < nums.size() - k + 1; i++) { // loop through except the last k - 1 elements
        if (i > start && nums[i - 1] == nums[i])
          continue;
        candidate.emplace_back(nums[i]);
        kSum(nums, candidate, target - nums[i], result, k - 1, i + 1);
        candidate.pop_back();
      }
      return;
    }
    
    int l = start;
    int r = nums.size() - 1;
    while (l < r) {
      int twoSum = nums[l] + nums[r];
      if (twoSum == target) {
        candidate.emplace_back(nums[l]);
        candidate.emplace_back(nums[r]);
        result.emplace_back(candidate);
        candidate.erase(candidate.begin() + 2, candidate.end());
        l++;
        while (l < r && nums[l - 1] == nums[l])
          l++;
      }
      else if (twoSum > target) {
        r--;
      }
      else {
        l++;
      }
    }
  }

public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4)
      return {};

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> candidate;
    kSum(nums, candidate, target, result, 4, 0);
    return result;
  }
};