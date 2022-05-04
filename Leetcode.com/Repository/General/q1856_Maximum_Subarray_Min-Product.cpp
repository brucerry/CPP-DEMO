// https://leetcode.com/problems/maximum-subarray-min-product/

#include <vector>
#include <stack>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maxSumMinProduct(vector<int>& nums) {
    vector<long> prefixSum { 0 };
    for (const int& num : nums) {
      prefixSum.emplace_back(prefixSum.back() + num);
    }
    
    long result = 0;
    
    stack<pair<int, int>> stack; // index, minVal
    for (int i = 0; i < nums.size(); i++) {
      int index = i;
      while (stack.size() and nums[i] < stack.top().second) {
        auto [ j, minVal ] = stack.top();
        stack.pop();
        
        index = j;
        result = max(result, (long)(prefixSum[i] - prefixSum[j]) * minVal);
      }
      stack.emplace(index, nums[i]);
    }
    
    while (stack.size()) {
      auto [ i, minVal ] = stack.top();
      stack.pop();
      
      result = max(result, (long)(prefixSum.back() - prefixSum[i]) * minVal);
    }
    
    return result % 1000000007;
  }
};