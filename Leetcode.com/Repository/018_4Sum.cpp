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
        if (i > start && nums[i - 1] == nums[i]) continue;
        candidate.emplace_back(nums[i]);
        kSum(nums, candidate, target - nums[i], result, k - 1, i + 1);
        candidate.pop_back();
      }
      return;
    }
    
    int left = start;
    int right = nums.size() - 1;
    while (left < right) {
      int twoSum = nums[left] + nums[right];
      if (twoSum == target) {
        candidate.emplace_back(nums[left]);
        candidate.emplace_back(nums[right]);
        result.emplace_back(candidate);
        candidate.erase(candidate.begin() + 2, candidate.end());
        left++;
        while (left < right && nums[left - 1] == nums[left]) left++;
      }
      else if (twoSum > target) {
        right--;
      }
      else {
        left++;
      }
    }
  }

public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};

    vector<vector<int>> result;
    vector<int> candidate;
    sort(nums.begin(), nums.end());
    kSum(nums, candidate, target, result, 4, 0);
    return result;
  }
};