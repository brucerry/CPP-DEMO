// https://leetcode.com/problems/maximum-subarray-min-product/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    
    vector<long> prefixSum (n + 1);
    for (int i = 1; i <= n; i++) {
      prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }
    
    long result = 0;
    stack<pair<int, int>> stack; // index, min value
    for (int i = 0; i < n; i++) {
      int index = i;
      while (stack.size() and stack.top().second > nums[i]) {
        auto [ j, minVal ] = stack.top();
        stack.pop();
        index = j;
        result = max(result, (prefixSum[i] - prefixSum[j]) * minVal);
      }
      stack.emplace(index, nums[i]);
    }
    
    while (stack.size()) {
      auto [ i, minVal ] = stack.top();
      stack.pop();
      result = max(result, (prefixSum[n] - prefixSum[i]) * minVal);
    }
    
    return result % 1000000007;
  }
};