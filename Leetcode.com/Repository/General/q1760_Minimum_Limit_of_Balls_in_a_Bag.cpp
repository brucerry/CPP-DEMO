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
    sort(nums.begin(), nums.end());
    
    int l = 1, r = nums.back();
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (canDivide(nums, maxOperations, m))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
  
private:
  bool canDivide(vector<int>& nums, int maxOperations, int minPenalty) {
    int op = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] <= minPenalty)
        break;
      int needOP = nums[i] / minPenalty - 1;
      if (nums[i] % minPenalty)
        needOP++;
      op += needOP;
    }
    return op <= maxOperations;
  }
};