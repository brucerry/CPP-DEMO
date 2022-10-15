// https://leetcode.com/problems/minimize-maximum-of-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minimizeArrayValue(vector<int>& nums) {
    long result = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      result = max(result, (sum + i) / (i + 1));
    }
    return result;
  }
};