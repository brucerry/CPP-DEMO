// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minMoves(vector<int>& nums, int k) {
    vector<int> indices { 0 };
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i])
        indices.emplace_back(i);
    }
    
    int n = indices.size();
    vector<long> preSum (n);
    for (int i = 1; i < indices.size(); i++) {
      preSum[i] = preSum[i-1] + indices[i];
    }
    
    long result = INT_MAX;
    for (int l = 1, r = k; r < n; l++, r++) {
      int m = l + ((r - l) >> 1), radius = m - l;
      long left = preSum[m - 1] - preSum[l - 1];
      long right = preSum[r] - preSum[m];
      long subtract = radius * (radius + 1);
      if ((k & 1) == 0) {
        left += indices[m];
        subtract += radius + 1;
      }
      result = min(result, right - left - subtract);
    }
    
    return result;
  }
};