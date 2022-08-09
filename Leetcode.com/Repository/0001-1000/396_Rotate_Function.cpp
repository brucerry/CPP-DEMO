// https://leetcode.com/problems/rotate-function/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxRotateFunction(vector<int>& nums) {
    int n = nums.size(), result = 0, sum = 0;
    
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      result += i * nums[i];
    }
    
    for (int cur = result, i = n - 1; i; i--) {
      cur += sum - n * nums[i];
      result = max(result, cur);
    }
    
    return result;
  }
};