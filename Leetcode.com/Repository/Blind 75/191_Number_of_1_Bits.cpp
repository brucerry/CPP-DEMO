// https://leetcode.com/problems/number-of-1-bits/

// time: O(1)
// space: O(1)

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
      n &= (n - 1);
      count++;
    }
    
    return count;
  }
};