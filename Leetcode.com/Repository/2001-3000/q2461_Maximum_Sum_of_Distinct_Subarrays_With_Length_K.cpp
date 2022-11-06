// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_set<int> uset;
    long result = 0, cursum = 0;
    for (int l = 0, r = 0; r < nums.size(); r++) {
      while (uset.count(nums[r]) or r - l + 1 > k) {
        cursum -= nums[l];
        uset.erase(nums[l++]);
      }
      cursum += nums[r];
      uset.emplace(nums[r]);
      if (uset.size() == k)
        result = max(result, cursum);
    }
    return result;
  }
};