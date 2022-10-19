// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int getMaxLen(vector<int>& nums) {
    int result = 0, pos = 0, neg = 0;
    for (const int& num : nums) {
      if (num > 0) {
        pos++;
        neg = neg == 0 ? 0 : neg + 1;
      }
      else if (num < 0) {
        int tmp = pos;
        pos = neg ? neg + 1 : 0;
        neg = tmp + 1;
      }
      else
        pos = neg = 0;
      result = max(result, pos);
    }
    return result;
  }
};