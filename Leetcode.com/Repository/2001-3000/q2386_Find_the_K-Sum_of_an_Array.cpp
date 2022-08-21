// https://leetcode.com/problems/find-the-k-sum-of-an-array/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n * log(n) + k * log(k))
// space: O(k)

class Solution {
public:
  long long kSum(vector<int>& nums, int k) {
    long long maxSum = 0;
    for (int& num : nums) {
      maxSum += max(0, num);
      num = abs(num);
    }
    sort(nums.begin(), nums.end());
    
    priority_queue<pair<long long, int>> maxHeap; // subsum, index of nums
    maxHeap.emplace(maxSum - nums[0], 0);
    
    long long result = maxSum;
    
    for (k--; k; k--) {
      auto [ subsum, i ] = maxHeap.top();
      maxHeap.pop();
      result = subsum;
      if (i + 1 < nums.size()) {
        maxHeap.emplace(subsum + nums[i] - nums[i+1], i+1);
        maxHeap.emplace(subsum - nums[i+1], i+1);
      }
    }
    
    return result;
  }
};