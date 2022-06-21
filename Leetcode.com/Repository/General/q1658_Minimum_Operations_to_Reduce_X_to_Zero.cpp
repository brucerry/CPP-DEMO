// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int target = sum - x;
    if (target == 0)
      return n;
    if (target < 0)
      return -1;
    
    int curSum = 0, len = INT_MIN;
    int l = 0;
    for (int r = 0; r < n; r++) {
      curSum += nums[r];
      while (curSum > target) {
        curSum -= nums[l++];
      }
      if (curSum == target)
        len = max(len, r - l + 1);
    }
    
    return len == INT_MIN ? -1 : n - len;
  }
};