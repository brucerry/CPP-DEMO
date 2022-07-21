// https://leetcode.com/problems/wiggle-subsequence/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class Greedy {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
      return n;
    
    int prevDiff = nums[1] - nums[0];
    int len = prevDiff ? 2 : 1;
    for (int i = 2; i < n; i++) {
      int curDiff = nums[i] - nums[i-1];
      if ((curDiff > 0 and prevDiff <= 0) or (curDiff < 0 and prevDiff >= 0)) {
        len++;
        prevDiff = curDiff;
      }
    }
    
    return len;
  }
};

// time: O(n)
// space: O(1)
class DP {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i-1] < nums[i])
        up = down + 1;
      else if (nums[i-1] > nums[i])
        down = up + 1;
    }
    return max(up, down);
  }
};