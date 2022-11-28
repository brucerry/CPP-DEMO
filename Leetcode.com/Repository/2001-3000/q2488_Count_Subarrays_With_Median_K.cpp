// https://leetcode.com/problems/count-subarrays-with-median-k/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> balCount;
    int res = 0, median_i = find(nums.begin(), nums.end(), k) - nums.begin();
    for (int i = median_i, bal = 0; i < nums.size(); i++) {
      bal += nums[i] == k ? 0 : nums[i] < k ? -1 : 1;
      balCount[bal]++;
    }
    for (int i = median_i, bal = 0; i >= 0; i--) {
      bal += nums[i] == k ? 0 : nums[i] < k ? -1 : 1;
      int balzero = balCount.count(-bal) ? balCount[-bal] : 0;
      int balone = balCount.count(-bal + 1) ? balCount[-bal + 1] : 0;
      res += balzero + balone;
    }
    return res;
  }
};