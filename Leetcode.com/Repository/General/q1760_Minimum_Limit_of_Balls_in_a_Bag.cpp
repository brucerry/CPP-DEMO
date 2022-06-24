// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

#include <vector>
#include <algorithm>
using namespace std;

// n = size of nums
// m = max of nums
// time: O(n * log(n) + n * log(m))
// space: O(log(n)) for sorting

class Solution {
public:
  int minimumSize(vector<int>& nums, int maxOperations) {
    sort(nums.rbegin(), nums.rend());
    
    int l = 1, r = nums[0];
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (canDivide(nums, maxOperations, m))
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
  
private:
  bool canDivide(vector<int>& nums, int maxOperations, int minPenalty) {
    int op = 0;
    for (const int& num : nums) {
      if (num <= minPenalty)
        break;
      int needOP = num / minPenalty - 1;
      if (num % minPenalty)
        needOP++;
      op += needOP;
    }
    return op <= maxOperations;
  }
};