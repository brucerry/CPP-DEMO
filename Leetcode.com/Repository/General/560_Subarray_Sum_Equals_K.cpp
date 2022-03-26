// https://leetcode.com/problems/subarray-sum-equals-k/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum { {0, 1} }; // prefixSum, count
    int sum = 0;
    int ans = 0;

    for (int& num : nums) {
      sum += num;
      ans += prefixSum[sum - k];
      prefixSum[sum]++;
    }

    return ans;
  }
};