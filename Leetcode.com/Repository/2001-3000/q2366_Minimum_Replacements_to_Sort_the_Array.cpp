// https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long minimumReplacement(vector<int>& nums) {
    long long op = 0;
    for (int i = nums.size() - 2, prev = nums.back(); i >= 0; i--) {
      int needOp = nums[i] / prev;
      if (nums[i] % prev) {
        needOp++;
        prev = nums[i] / needOp;
      }
      op += needOp - 1;
    }
    return op;
  }
};