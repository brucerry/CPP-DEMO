// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int result = 0, len = 0, largest = 0;
    for (const int& num : nums) {
      if (num > largest) {
        largest = num;
        len = result = 0;
      }
      len = num == largest ? len + 1 : 0;
      result = max(result, len);
    }
    return result;
  }
};